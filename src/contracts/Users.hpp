#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <string>
#include <vector>


namespace rts {
    using namespace eosio;
    using std::string;

    class Users : public contract {
        using contract::contract;

    public:

        Users(account_name self) : contract(self) {}

        // @abi action
        void add(const account_name account, string &username);


    private:

        // @abi table user i64
        struct user {
            uint64_t account_name;
            string username;

            uint64_t primary_key() const { return account_name; }

            EOSLIB_SERIALIZE(user, (account_name)(username));
        };
        typedef multi_index<N(user), user> userIndex;
    };

    EOSIO_ABI(Users, (add));
}