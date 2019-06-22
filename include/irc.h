#pragma once
#include <stdbool.h>
#include <openssl/ssl.h>
#define BUFF_SIZE 512

typedef struct
{
    int sockfd;
    struct addrinfo *res;
    char const *nick, *username, *realname;
    bool sslflag, nonblockflag;
    SSL *ssl;
    SSL_CTX *ctx;
} irc_t;

irc_t *newIrc(char const *server,
              char const *port,
              char const *nick,
              char const *username,
              char const *realname,
              bool ssl, bool nonblockflag);
int freeIrc(irc_t *in);
int ircConnect(irc_t *in);
int ircSend(irc_t const *in, char const *fmt, ...) __attribute__((format(printf, 2, 3)));
char *ircRead(irc_t const *in);

int ircJoin(irc_t const *in, char const *channel);
int ircQuit(irc_t const *in, char const *msg);

extern char *RFC2812;
enum
{
    VAR,
    IDENT,
    NICK,
    USERNAME,
    HOST,
    VERB,
    PARAMS,
    MSG
};