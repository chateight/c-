/*
 from http://pract.webcrow.jp/pages/contents/c/pointer/pointer-of-func
*/

#include <stdio.h>
/* わかりやすいようにtypedefして使う */
typedef int8_t	(*p_func_type)(int32_t);
/****************************
コールバックとは関係無い関数
******************************/
int32_t	func1(void)
{
	int32_t	rc;
	// 何か適当に処理
	return (rc);
}

/************************
いろいろ処理したい関数
*************************/
void func_task(p_func_type p_func, int32_t func_arg, int8_t *func_ret)
{
	int32_t	ret_code;

	ret_code = func1();

	switch (ret_code) {
		case (1):
			// 処理A
			*func_ret = p_func(func_arg);
			break;
		case (2):
			// 処理B
			break;
		case (3):
			// 処理C
			break;
		default:
			// 処理D
			break;
	}
}
/************************
コールバック用関数1
*************************/
int8_t func_callback1(int32_t val)
{
	int8_t rc = 0;
	if( 0 == (val%3) ) {
		rc = 1;
	}
	return (rc);
}
/************************
コールバック用関数2
*************************/
int8_t func_callback2(int32_t val)
{
	int8_t rc = 0;
	if( 1000 < (val*val) ) {
		rc = 1;
	}
	return (rc);
}
/************************
main関数
*************************/
int main (void) {
	p_func_type		p_func;
	int8_t			rc;

	p_func = func_callback1;
	func_task(p_func, 10, &rc); // rcにコールバックの戻り値が入る
    printf("%d\n", rc);
	p_func = func_callback2;
	func_task(p_func, 10, &rc); // rcにコールバックの戻り値が入る
    printf("%d\n", rc);
	printf("%p\n", &rc);	
	return (0);
}