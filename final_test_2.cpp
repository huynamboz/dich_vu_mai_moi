#include<stdio.h>
#include <string.h>
#include<conio.h>

struct hovaten {
    char ten[50];
    int stt[50];
};
struct noiDung
{
    char nd[50]; // nội dung sở thích
    int stt[100]; //số thứ tự của mỗi thằng
};
struct SoThich
{
    int sl[100]; // sô lượng sở thích của từng thằng
    noiDung x[10]; //từng sở thích của mỗi nhóm hobbie[i]
};
//-----cái struct có chữ Check hoặc _c phía sau dùng để lưu dữ liệu nhập vào --///
struct noiDungCheck
{
    char nd_c[50]; //
    int sl_c[100];
};
struct SoThichCheck
{
    noiDungCheck xCheck[10];
    char name[50]; // tên đứa vừa nhập
};
//---------------------------//

void xoaxuongDong (char x[]){ 
    size_t len = strlen(x);
   // TITV\n\0 => TITV\E\0
    if(x[len-1]=='\n'){
        x[len-1]='\0';
    }
}
int main(){
  
    hovaten hoten[10];
    SoThich hobbie[10]; // số nhóm sở thích ( mỗi nhóm là các sở thích của 1 thằng)
    SoThichCheck hobbie_c; // tương tự cái hobbie nhưng có _c phía sau có nghĩa là check để lưu các sở thích nhập vào, vì mình nhập vào có 1 đứa nên k dùng mảng cho hobbie_c
   int stt,a;



//--code đọc data nhập vào---//  
      char sex[10];
      char choose;
      printf("nhap ten :");
      gets(hobbie_c.name);
      printf("nhap gioi tinh :");
      fflush(stdin);
      scanf("%s",sex);
    int soluong;
    printf("nhap so luong so thich :");
    scanf("%d",&soluong);
    printf("nhap so thich :");
    for (int i = 1; i <= soluong; i++)
    {
      fflush(stdin);
      gets(hobbie_c.xCheck[i].nd_c);
    }
//---kết thúc code đọc data nhập vào--//

  
    
//---code đọc data từ file--//
  int i=0,count; 
  if (sex[1] == 'u')
  {
      FILE *st = fopen("nam.txt","r");
    
   while(!feof(st))
     {
      i++;
      fscanf(st,"%d %d",&hobbie[i].x[i].stt[i],&hobbie[i].sl[i]); //đọc số thứ tự và số lượng sở thích
      fgets(hoten[i].ten,50, (FILE*)st ); // vì tên có nhiều từ nên phải dùng fgets để lấy hết chuỗi
       xoaxuongDong(hoten[i].ten);// vì hàm fgets nó sẽ đọc luôn ký tự xuống dòng nên việc so sánh sẽ không đúng nên sẽ dùng hàm xoaxuongdong()
      count = hobbie[i].x[i].stt[i]; //biến count để lưu số lượng person
       for (int j = 1; j <= hobbie[i].sl[i]; j++)
       {
         fgets(hobbie[i].x[j].nd,50,(FILE*)st );
         xoaxuongDong(hobbie[i].x[j].nd);
       }
     } fclose(st);
  } else {
    FILE *st = fopen("nu.txt","r");
    while(!feof(st))
     {
      i++;
      fscanf(st,"%d %d",&hobbie[i].x[i].stt[i],&hobbie[i].sl[i]); 
      fgets(hoten[i].ten,50, (FILE*)st );
      xoaxuongDong(hoten[i].ten);
      count = hobbie[i].x[i].stt[i];
        for (int j = 1; j <= hobbie[i].sl[i]; j++)
        {
         fgets(hobbie[i].x[j].nd,50, (FILE*)st );
         xoaxuongDong(hobbie[i].x[j].nd);
        }
     } fclose(st);
  }
//--- kết thúc code đọc data từ file---//
  



//----code tìm sở thích giống nhiều nhất--//
int dem[100];
for (int i = 1; i <= count; i++)
{
        for (int  j = 1; j <= soluong; j++)
        {
            for (int k =1 ; k <= hobbie[i].sl[i] ; k++)
            { 
                // printf("%s-%s\n",hobbie_c.xCheck[j].nd_c,hobbie[i].x[k].nd);
               if ( strcmp(hobbie_c.xCheck[j].nd_c,hobbie[i].x[k].nd) == 0) {
                   dem[i]++;
                   break;
               }
            }
        }
}
//---kết thúc code đọc sở thích giống nhiều nhất---//

//----tìm những thằng giống nhất để in ra--//
int d=0;
int soTT=1;
int max=dem[1];
for (int i = 1; i <= count-1; i++)
{
    if (dem[i]>max)
    {
       max =dem[i];
       soTT =i;
    }
//  printf("%d\n",dem[i]);   
} 
for (int i = 1; i <= count-1; i++)
{
    if ( dem[i] == max ){
          printf("%d %s ->> So thich : ",++d,hoten[i].ten);
             for (int j = 1; j <=hobbie[i].sl[i]; j++)
               {
                   printf("%s, ",hobbie[i].x[j].nd);
               } printf("\n----------------\n");
    }
}








/*
  for (int i = 1; i <= count; i++)
 
  
   {
       printf("ten: %s",hoten[i].ten);
       printf("so thich :\n");
       for (int j = 1; j <=hobbie[i].sl[i]; j++)
       {
           printf("%s",hobbie[i].x[j].nd);
           
       } printf("\n----------------\n");
       
      
   }
*/
  
  
}