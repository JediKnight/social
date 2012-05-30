#include "twitter.h"

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
  yajl_val node;
  unsigned char fdata[65536];
  char errbuf[1024];
  size_t rd;

  fdata[0] = errbuf[0] = 0;

#ifdef _DEBUG_
  char *url = "http://api.twitter.com/statuses/user_timeline/X2xAmpJDY3GMvq.json";
  char *req_url = NULL;
  char *jstr = NULL;

  req_url = oauth_sign_url2(url, NULL, OA_HMAC, "GET", consumer_key, consumer_secret, access_token, access_token_secret);

  if((jstr = oauth_http_get(req_url, NULL)) == NULL)
    {
      fprintf(stderr, "oauth_http_get\n");
      exit(EXIT_FAILURE);
    }
#endif

  rd = fread((void *)fdata, 1, sizeof(fdata) - 1, stdin);

  if (rd == 0 && !feof(stdin))
    {
      fprintf(stderr, "error encountered on file read\n");
      exit(EXIT_FAILURE);
      
    }

  else if (rd >= sizeof(fdata) - 1)
    {
      fprintf(stderr, "config file too big\n");
      exit(EXIT_FAILURE);
    }
  
  node = yajl_tree_parse((const char *)fdata, errbuf, sizeof(errbuf));

  if (node == NULL)
    {
      fprintf(stderr, "parse_error: ");

      if (strlen(errbuf))
	{
	  fprintf(stderr, " %s", errbuf);
	}

      else
	{
	  fprintf(stderr, "unknown error");
	}

    fprintf(stderr, "\n");

    return 1;
    }

  else
    {
      const char *path[] = { "text", (const char *) 0 };
      yajl_val v = yajl_tree_get(node, path, yajl_t_string);

      if (v)
	{
	  printf("%s: %s\n", path[0], YAJL_GET_STRING(v));
	}
      
      else
	{
	  printf("no such node: %s\n", path[0]);
	}
    }

  yajl_tree_free(node);

  return 0;
}

int main()
{
  /* twpost("test post"); */
  twget();
  return 0;
}
