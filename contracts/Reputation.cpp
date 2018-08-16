#include "Reputation"

namespace rts {
    void Reputation::adduser(const account_name account, string &username, vector <alias> &aliases) {
        require_auth(account);
        userIndex users(_self, _self);

        auto iterator = users.find(account);
        eosio_assert(iterator == users.end(), "Address for account already exists");

        users.emplace(account, [&](auto &user) {
            user.account_name = account;
            user.username = username;
        });
    }

}