# Reputation Tracking System

## Overview 

There is a distinct need for a reputation tracking system, hereby RTS, that can be run on the EOS blockchain that simplifies the user experience and allows for a token based rating and reviewing system to incentive users to the platform. While Scatter and other open source rating system exist, these have a steep learning curve that makes the platform inaccessible to some users. These systems generally have the weakness of a single centralized authority. 

## Methodology.

To Track the reputation of users through both the scoring of transactions as positive and negative and through the scoring of a voting system to ensure authenticity.

## User classes:

There shall be three user classes within the system. Unregistered users, registered users, and arbiters. 

Unregistered users are able to view the votes and transactions without having an account on any service. 

Users are registered users that must have an EOS account and the scatter chrome extension installed. The scatter chrome extension will be used as an auth service.

Arbiters are community nominated users. An arbiter has the Authority to vote on the authenticity of the item submitted reputation item. To incentive users to participate in the system, an arbiter will be given a foxed of amount of token per vote to track their participation and their intentions within the system.

## Reputation Transaction:

Registered users shall be able to submit a positive, neutral, or negative score to rate a transaction on other users as well as the proof necessary to verify the transaction. The user shall be able to submit a record of their tranasction regardless if the user other user is on the RTS platform. If the other user has an account on the RTS platform, then both users will gain a fixed amount of token upon the verification of the transaction.

## Tracking intentions:
To ensure that every arbiter has the best interest of the tracking sytem at heart with each of their votes, their consensus score shall be tracked, averaged, and judged over a certain number of votes. If an arbiter is unable to maintian a 60% consensus with the rest of the arbiters score over a period of 20 votes, then they will be demoted from their position as arbiter. A demotion does not preclude the community from re-electing the user an arbter. 

The reputation of a user shall consist of two variables. The reputation itself, and the consensus score. 
