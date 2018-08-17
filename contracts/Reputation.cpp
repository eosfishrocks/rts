#include "Reputation.hpp"

namespace rts {
    void Reputation::adduser(const account_name account, string &username, vector <alias> &aliases) {
        require_auth(account);
        userIndex users(_self, _self);

        auto iterator = users.find(account);
        eosio_assert(iterator == users.end(), "Address for account already exists");

        users.emplace(account, [&](auto &user) {
            user.account_name = account;
            user.username = username;
            user.aliases = aliases;
        });
    }

    void Reputation::link(const account_name account, vector <alias> &aliases) {
        require_auth(account);
        vector <alias> foundAliases;
        userIndex users(_self, _self);

        auto iterator = users.find(account);
        eosio_assert(iterator != users.end(), "Address for account not found");

        users.modify(iterator, account, [&](auto &user) {
            for (auto& newAlias : aliases) {
                for (auto& foundAlias : user.aliases){
                    if(newAlias.username == foundAlias.username && newAlias.network == foundAlias.network)
                        foundAliases.push_back(newAlias);
                }
            }
        });
    }

    void Reputation::submit(const account_name account, string &name, vector <alias> &aliases,
                            uint64_t &date, uint64_t &submitter, vector <string> &proof) {
        require_auth(account);

        repIndex reputations(_self, _self);

        reputations.emplace(account, [&](auto &report) {
            report.name = name;
            report.aliases = aliases;
            report.date = date,
            report.submitter = submitter;
            report.proof = proof;
        });
    }
}