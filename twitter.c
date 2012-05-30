#include "twitter.h"

/* char *escape_dquote(char *str) */
/* { */
/*   int i,j = 0; */
/*   char *buf; */

/*   /\* */
/*    * エスケープ対象の文字数算出 */
/*    *\/ */
/*   for(i = 0; i < strlen(str); i++) */
/*     { */
/*       if(str[i] == '"') */
/* 	{ */
/* 	  j++; */
/* 	} */
/*     } */

/*   /\* */
/*    * 渡された文字列 + エスケープする文字数分のメモリ確保 */
/*    *\/ */
/*   buf = malloc(strlen(str) + j); */

/*   /\* */
/*    * "をエスケープ */
/*    *\/ */
/*   for(i = 0, j = 0; i < strlen(str); i++, j++) */
/*     { */
/*       if(str[i] == '"') */
/* 	{ */
/* 	  buf[j++] = '\\'; */
/* 	} */

/*       buf[j] = str[i]; */
/*     } */

/*   return buf; */
/* } */

int twpost(char *msg)
{
  char *req_url = NULL;
  char *url = strdup(test_call_uri);

  req_url = oauth_sign_url2(url, &msg, OA_HMAC, "POST", consumer_key, consumer_secret, access_token, access_token_secret);
  oauth_http_post2(req_url, msg, "Expect: \r\n");

  return 0;
}

int twget()
{
  char *url = "http://api.twitter.com/statuses/user_timeline/X2xAmpJDY3GMvq.json";
  char *req_url = NULL;
  struct json_object *jstr;

  req_url = oauth_sign_url2(url, NULL, OA_HMAC, "GET", consumer_key, consumer_secret, access_token, access_token_secret);
  jstr = json_tokener_parse(oauth_http_get(req_url, NULL));
  /* printf("jstr.to_string() = %s\n", json_object_to_json_string(jstr)); */
  json_object_object_foreach(jstr, key, val) printf("(key, val) = (%s, %s)\n", key, json_object_get_string(val));

  json_object_put(jstr);

  return 0;
}

int main()
{
  /* twpost("test post"); */
  twget();
  return 0;
}
