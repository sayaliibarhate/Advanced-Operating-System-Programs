#include <stdio.h>
#include <malloc.h>

int main()
{
	struct mallinfo mi = mallinfo();

	printf("Total non-mapped bytes (arena) : %d\n",mi.arena);
	printf("# of free chunks (ordblks) : %d\n",mi.ordblks);
	printf("# of free fastbin blocks (smblks) : %d\n",mi.smblks);
	printf("Bytes in mapped regions (hblkhd) : %d\n",mi.hblkhd);
	printf("Maximum total allocated space (usmblks) : %d\n",mi.usmblks);
	printf("Free bytes held in fastbins (fsmblks) : %d\n",mi.fsmblks);
	printf("Total allocated space (uordblks) : %d\n",mi.uordblks);
	printf("Total free space (fordblks) : %d\n",mi.fordblks);
	printf("Topmost released block (keepcost) : %d\n",mi.keepcost);

	return 0;
}
