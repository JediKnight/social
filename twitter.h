#ifndef _TWITTER_H_
#define _TWITTER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <oauth.h>
/* #include <json/json.h> */
#include <yajl/yajl_tree.h>

const char *own = "X2xAmpJDY3GMvq";
const char *consumer_key = "UBr9VDErATmbbNPwhwdUgw";
const char *consumer_secret = "wCLBEaHEbmVjnSNDIWZOASfWZMYZaSKLa7Rh5J7gy8";
const char *access_token = "391117822-hK8VRF93LPfwVGcgFF41pO684PcnHLJWqBZoGUMw";
const char *access_token_secret = "MeCyF2mLiww8HErdETWK3814PAlscoXsRJFeYdozrk";
const char *test_call_uri = "http://api.twitter.com/1/statuses/update.json";
/* const char *request_token_url = "https://api.twitter.com/oauth/request_token"; */
/* const char *authorize_url = "https://api.twitter.com/oauth/authoriz"; */
/* const char *access_token_url = "https://api.twitter.com/oauth/access_token"; */

int twpost(char *);
int twget();

#endif	/* _TWITTER_H_ */
