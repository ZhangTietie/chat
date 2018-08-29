#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <hiredis/hiredis.h>

int gxupdate(UDF_INIT *initid,UDF_ARGS *args,char *is_null,char *error)
{
	redisContext *c = redisConnect("127.0.0.1",6379);
	if(c->err)
	{
		redisFree(c);
		return 1;
	}

	const char *command1 = "hset %s name %s password %s";
	redisReply *r = (redisReply *)redisCommand(c,command1,args->args[0],args->args[1],args->args[2]);
	if(r == NULL)
		return 1;
	
	if( !((r->type == REDIS_REPLY_STATUS) && (strcasecmp(r->str,"ok")==0)) )
	{
		freeReplyObject(r);
		redisFree(c);
		return 1;
	}
	freeReplyObject(r);
	return 0;
}

my_bool gxupdate_init(UDF_INIT *initid,UDF_ARGS* args,char *message)
{
	return 0;
}
