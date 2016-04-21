#include <stdio.h>

/* API, подлежащий реализации */
struct greet_api
{
	int (*say_hello)(char *name);
	int (*say_goodbye)(void);
};

/* Наша реализация функции hello */
int say_hello_fn(char *name)
{
	printf("Hello %s\n", name);
	return 0;
}

/* Наша реализация функции goodbye */
int say_goodbye_fn(void)
{
	printf("Goodbye\n");
	return 0;
}

/* Структура данных, реализующая API */
struct greet_api greet_api =
{
	.say_hello = say_hello_fn,
	.say_goodbye = say_goodbye_fn
};

/* main() не нужно знать ничего о том, как функции say_hello/goodbye реализованы,
 * main() просто знает, что они делают */
int main(int argc, char *argv[])
{
	greet_api.say_hello(argv[1]);
	greet_api.say_goodbye();

	printf("%p, %p, %p\n", greet_api.say_hello, say_hello_fn, &say_hello_fn);

	exit(0);
}
