#include <iostream>
#include <string.h>
#include <errno.h>
#include <error.h>
#include <hiredis/hiredis.h>

using namespace std;
int main()
{
	redisContext* c = redisConnect("127.0.0.1",6379);
	if( c->err )
    	{
        	redisFree(c);
        	cerr<<"connect to redisServer fail"<<errno<<endl;
		return 0;
    	}
	string command = "hset test2 name test2 password 1";
	redisReply *r = (redisReply*)redisCommand(c,command.c_str());

    	if( NULL == r)
    	{
        	cerr<<"Execut command1 failure:"<<errno<<endl;
        	return 0;
    	}
	cout<<r->type<<endl;
	return 0;
    	if(r->type == REDIS_REPLY_STRING )
    	{
        	cout<<r->str<<endl;
    	}
	if(r->type == REDIS_REPLY_NIL)
	{
		cout<<"not find"<<endl;
	}
	freeReplyObject(r);
	return 0;
}
