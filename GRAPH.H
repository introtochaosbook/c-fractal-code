#include <graphics.h>

void startgraph(void)
{
	/* request autodetection */
	int gdriver = DETECT, gmode, errorcode;

	/* initialize graphics mode */
	initgraph(&gdriver, &gmode, "");

	/* read result of initialization */
	errorcode = graphresult();

	if (errorcode != grOk) /* an error occurred */
	{
		printf("Graphics error: %s\n",grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);			/* return with error code */
	}
	return;
}

