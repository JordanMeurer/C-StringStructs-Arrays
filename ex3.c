#include<stdio.h>
#include<stdlib.h>

typedef struct Rect
{
	double x;
	double y;
	char color;
	double w; //width
	double h; //height
} RectT;

int chk_overlap(RectT *r1, RectT *r2, int j);
void CreateRecs(RectT *recs, RectT a, RectT b);
void printjunk(int test);
/* I had an issue if I did not put this scanf in the main rather than another function, so I left it in the main*/
int main()
{
	int test = 5;
	int i = 0;
	RectT a, b, *recs;
	printf("Please enter the x cordinate for a\n");
        scanf("%lf", &a.x);
        printf("Please enter the y cordinate for a\n");
        scanf("%lf", &a.y);
        printf("Please enter the width cordinate for a\n");
        scanf("%lf", &a.w);
        printf("Please enter the height cordinate for b\n");
        scanf("%lf", &a.h);
        printf("Please enter the x cordinate for b\n"); 
        scanf("%lf", &b.x);
        printf("Please enter the y cordinate for b\n");
        scanf("%lf", &b.y);  
        printf("Please enter the width cordinate for b\n");
        scanf("%lf", &b.w);
        printf("Please enter the height cordinate for b\n");
        scanf("%lf", &b.h);
	test = chk_overlap(&a, &b, i);
	printjunk(test);
	CreateRecs(recs, a, b);
	return 0;

}
/*The function that checks if the rectangles overlap*/
int chk_overlap(RectT *r1,RectT *r2, int j)
{
	if(r1->x+r1->w < r2[j].x||r2[j].x+r2[j].w < r1->x||r1->y+r1->h < r2[j].y||r2[j].y+r2[j].h < r1->y)
		return 0;
	else
		return 1;
}
/*creates the recs, generates the random rectangles, and sends them to see if they overlap a or b*/
void CreateRecs(RectT *recs, RectT a, RectT b)
{
	int i, j, count = 0;
	recs = malloc(50*sizeof(RectT));
	for(i = 0; i < 50; i++){
		recs[i].x = (rand()%20) + 1;
		recs[i].y = (rand()%20) + 1;
		recs[i].w = (rand()%20) + 1;
		recs[i].h = (rand()%20) + 1;
	}
	for(j = 0; j < 50; j++){
		if(chk_overlap(&a, recs, j) == 1 || chk_overlap(&b, recs, j) == 1)
			count++;
	}
	printf("The randomly generated rectangles overlapped a or b %d times\n", count);
	free(recs);
}		
/*More print stuff I didn't want in the already cluttered main*/
void printjunk(int test)
{
	if(test == 0)
		printf("a and b do not overlap\n");
	else
		printf("a and b do overlap\n");
}
