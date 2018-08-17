#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <string>
#include <vector>


namespace rts {
    using namespace eosio;
    using std::string;

    class Reputation : public contract {
        using contract::contract;

    public:

        Reputation(account_name self) : contract(self) {}

        // Internal Config structure. Keeps times to prevent election logic from eating up cpu.
        // @abi table config i64
        struct config{
            uint64_t latest_vote; // Latest vote
            uint64_t latest_run; // Last time an election calculation was run
            string token_location; // Token contract location
            string token_symbol; // Token Symbol
            EOSLIB_SERIALIZE(config, (latest_vote)(latest_run)(token_location)(token_symbol));

        };

        // Table for aliases for submitted reports
        // @abi table alias i64
        struct alias
        {
            string username; // External username
            string network; // External network
            EOSLIB_SERIALIZE(alias, (username)(network));
        };
        typedef  multi_index<N(alias), alias> aliasIndex; // Total Alias Index
        typedef  multi_index<N(alias), alias> aAliasIndex; // Index of Accepted Aliases

        // Vote structure for arbiter and reputation elections
        // @abi table vote i64
        struct vote {
            uint64_t vote_id;
            uint64_t account_id; // Account of voter
            uint64_t value; // -1, 0, 1 in Reputation elections, 1 in arbiter elections
            uint64_t primary_key() const { return vote_id; }
            EOSLIB_SERIALIZE(vote, (account_id)(value));
        };
        typedef multi_index<N(vote), vote> voteIndex;

        // Reputation election table
        // @abi table relection i64
        struct relection {
            uint64_t election_id;
            vector <vote> votes; // Vector containing votes for election
            string name; // Name on RTS net
            vector <alias> aliases; // List of aliases
            uint64_t date; // date of report submission
            uint64_t submitter; // account of submitter
            string result; // Result
            vector <string> proof; // Serialized string of {[account:storageIds]} for storage network
            uint64_t primary_key() const { return election_id; }
            EOSLIB_SERIALIZE(relection, (election_id)(votes)(name)(aliases)(date)(submitter)(result)(proof));
        };
        typedef multi_index<N(relection), relection> repIndex;

        // Arbiter election table
        // @abi table aelection i64
        struct aelection{
            uint64_t election_id;
            vector <vote> votes;
            uint64_t date;
            uint64_t primary_key() const { return election_id; }
            EOSLIB_SERIALIZE(aelection, (election_id)(votes)(date));
        };
        typedef multi_index<N(relection), relection> arbiterIndex;

        // Registered user table structure.
        // @abi table user i64
        struct user {
            uint64_t account_name; // EOS Acconut
            string username; // Name for RTS
            vector <relection> reputations; // List of linked elections

            string role; // Role 'user' otherwise 'arbiter' if elected
            vector <alias> aliases; // List of external aliases
            uint64_t consensus; // total consensus score
            vector <uint64_t> latest_consensus; // Vector to be used for the last twenty consensus scores
            uint64_t primary_key() const { return account_name; }

            EOSLIB_SERIALIZE(user, (account_name)(username)(reputations)(role)(aliases)(consensus)(latest_consensus));
        };
        typedef multi_index<N(user), user> userIndex;

        // Creates a user on the network
        // @abi action
        void adduser(const account_name account, string &username, vector <alias> &aliases);

        // Links a user to an external username
        // @abi action
        void link(const account_name account, vector<alias> &aliases);

        // Submits a reputation report
        void submit(const account_name account, string &name, vector<alias> &aliases,
                uint64_t &date, uint64_t &submitter, vector<string> &proof);

        // Votes for a user in the current election if election is active
        // @abi action
        void elect(const account_name account, uint64_t &account_name);

        // Votes on an election report
        // @abi action
        void evote(const account_name account, uint64_t &repid, uint64_t result);

        // External function available to run as a scheduled task
        // @abi action
        void run(const account_name account);

    private:
        // Calculates the result of active elections
        void runelections();

        // Links new users to previously submitted reports
        void linkusers();
    };

    EOSIO_ABI(Reputation, (adduser)(link)(submit)(elect)(evote)(run));
}