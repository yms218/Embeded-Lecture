#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 함수 포인터 사용하는 이유
// 윈도우 파일 시스템 fat, ntfs
// 리눅스 1000개 넘음 open이라는 함수 : 파일을 여는 함수
// 파일마다 open이 달라야함 open을 바꿔가면서 프로그래밍 하면 불편함
// open하면 알아서 현재 파일시스템에 적절한 open함수를 넣고 system call을 동작시켜라
// 상황에 따라서 동작하는 함수를 바꿔줄수 있다.(이름은 동일하게)
#define SYSCALL_NUM 256
int randnum;
void *sys_call_table[SYSCALL_NUM] = {0};

int my_open(char *str)
{
	printf("my_open() System Call\n");
	printf("str = %s\n", str);
}

int test_open(char *str, int meta1, int meta2)
{
	printf("test_open() System Call \n");
	printf("str = %s\n", str);
	printf("meta1 = %d, meta2 = %d\n", meta1, meta2);
}

int my_read(int fd, char *buf, int size)
{
	printf("my_read() System Call\n");
	printf("fd = %d, buf = %s, size = %d\n", fd, buf, size);
}

int my_write(int fd, char *buf, int size)
{
	printf("my_write() System Call\n");
	printf("fd = %d, buf = %s, size = %d\n", fd, buf, size);
}

void my_close(int fd)
{
	printf("my_close() System Call\n");
	printf("fd = %d\n", fd);
}


void kill_proc(int signum)
{
	printf("signum = %d\n", signum);
}

// void (*)(int) my_signal(int signum, void (* handler)(int))
// void (*)(int) (*)(int signum, void (* handler)(int))
void (* my_signal(int signum, void (* handler)(int)))(int)
{
	printf("my_signal() System Call\n");
	printf("signum = %d\n", signum);
	handler(signum);
	return kill_proc;
}

void init_sys_call_table(void)
{
	// 만약 NTFS 파일 시스템이면 ntfs_open
	// 만약 EXT3 파일 시스템이면 ext3_open
	// 만약 EXT2 파일 시스템이면 ext2_open
	// 만약 FAT 파일 시스템이면 fat_open
	// YAFFS 파일 시스템이라면 yaffs_open
	// 여기서 sys_call_table[0]은 open()이라 봐도 됨
	// 즉 open()을 호출하면 알아서 파일 시스템을 감지하고
	// 적절한 fat_open, ntfs_open, ext2_open이
	// 알아서 동작되도록 만들어 주는 것
	srand(time(NULL));	
	
        randnum = rand() % 2 + 1;

	if(randnum % 2)
		sys_call_table[0] = my_open;
	else
		sys_call_table[0] = test_open;
	
	sys_call_table[1] = my_read;
	sys_call_table[2] = my_write;
	sys_call_table[3] = my_close;
	sys_call_table[4] = my_signal;
}


void syscall(int syscall_num)
{
	int fd = 3;
	int kill_signal = 9;
	char filename[32] = "test.txt";
	char buf[32] = "contents";
	int len = strlen(buf);

	switch(syscall_num)
	{
		case 0 : // int (*)(char *, int, int) - 짝수
			// int (*)(char *)  - 홀수
			if(randnum%2)
			     ((int (*)(char *))sys_call_table[0])(filename);
			else
			     ((int (*)(char *, int, int))sys_call_table[0])(filename, 23423, 6856059);
			break;
		case 1 : // int (*)(int , char *, int)
			((int (*)(int, char *, int))sys_call_table[1])(fd, buf, len);
			break;
		case 2 : // int (*)(int , char *, int)
			((int (*)(int, char *, int))sys_call_table[2])(fd, buf, len);
			break;
		case 3 : // void (*)(int)
			((void (*)(int))sys_call_table[3])(fd);
			break;

		case 4 : // void (*)(int) (*)(int, void (*)(int))
			// void(* (*)(int, void (*)(int)))(int)
			((void (* (*)(int, void (*)(int)))(int))sys_call_table[4])(kill_signal, kill_proc);
			break;
		default :
			printf("There are no syscall Number\n");
			break;
	}

}

int main(void)
{
	int i;
	init_sys_call_table();	
	for(i=0; i<5; i++)
		syscall(i);
	return 0;
}

