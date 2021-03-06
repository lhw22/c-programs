#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int n,a[10000000],b[1000000];
//大作业不牵扯多个数组 ，所以用全局变量 
//n为方便设成全局变量� 
int ma1=1,ma2,ma3;//代表三层菜单 
int x,y,am,wi;//x,y代表输入的参数，am表示一行数量，wi表示宽度 
void swap(int i,int j){
	int t;
	t=a[i];a[i]=a[j];a[j]=t;
}
void inc(int i) {
n+=i;
}
void printarr(){//为编程方便，程序全部用小写，关键字（如delete）用其他名称替代 
    int i;
    for(i=0;i<n;i++){
    	printf("%*d",wi,a[i]); if ((i+1)%am==0)printf("\n");
	}putchar('\n');
}
void fill(int x){
	int i;
	for (i=0;i<n;i++) a[i]=x; 
}
void randomfill(int x,int y){
	int i;
	for (i=0;i<n;i++) a[i]=x+(rand())%(y-x);
}
void seqfill(int x,int y){
	int i;
	a[0]=x;
	for (i=1;i<n;i++) a[i]=a[i-1]+y;
}
void config(){
	printf("请输入数组元素个数\n");puts("");scanf("%d",&n);puts("");
	printf("请输入一行打印元素个数\n");puts("");scanf("%d",&am);puts("");
	printf("请输入每个元素的打印宽度\n");puts("");scanf("%d",&wi);puts("");
}
void read(){
	int i;
	puts("请依次输入各个值"); 
	for(i=0;i<n;i++) scanf("%d",&a[i]);puts("");
}
void reverse(){
	int i;
	for (i=0;i<n>>1;i++) swap(i,n-i-1);
}
void deletes(int id){
	int i;
	for (i=id;i<n-1;i++)a[i]=a[i+1];
	inc(-1);
}
void deleterange(int s,int t){
	int i;
	for (i=s;i<n+s-t-1;i++) a[i]=a[i+t-s+1];
	inc(s-t-1);
}
int search(int val){
	int i;
	for (i=0;i<n;i++) if (a[i]==val) return(i);
	return(-1);
}
int isasc(){
	int i;
	for (i=1;i<n;i++) if(a[i]<a[i-1]) return 0;
	return 1;
}
int isdesc(){
	int i;
	for (i=1;i<n;i++) if(a[i]>a[i-1]) return 0;
	return 1;
}
int isequal(){
	int i;
	for (i=1;i<n;i++) if(a[i]!=a[i-1]) return 0;
	return 1;
}
int max(){
	int i,max1=-2147483646,t;
	for (i=0;i<n;i++) if (a[i]>max1) {
		max1=a[i];t=i;
	}return(max1);
}
int min(){
	int i,min1=2147483647,t;
	for (i=0;i<n;i++) if (a[i]<min1) {
		min1=a[i];t=i;
	}return(min1);
}
float average(){
	int i;
	float sum=0;
	for(i=0;i<n;i++) sum+=a[i];
	return(sum/n);
}
void insert(int pos,int val){
	int i;
	for(i=n;i>pos;i--) a[i]=a[i-1];a[pos]=val;
	inc(1);
}
float orderinsert(int val){
    int i;
	if (isasc())
	 for(i=0;i<n;i++) if(a[i]>val){
	 insert(i,val);break;}
	if (isdesc())
	 for(i=0;i<n;i++) if(a[i]<val){
	  insert(i,val);break;}
}
float variation(){
	float sum=0,ave;
    int i;
	ave=average();
	for(i=0;i<n;i++) sum+=pow(a[i]-ave,2);
	return(sum/n);
}
float deviation(){
	return(sqrt(variation()));
}
void bubblesort(int x){//x代表升序与否，升序为1，降序为0 
	int i,j;
	if (x==1) for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++)if (a[j]>a[j+1]) swap(j+1,j); 
	if (x==0) for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++)if (a[j+1]>a[j]) swap(j+1,j); 
}
void selectsort(int x){//x代表升序与否，升序为1，降序为0 
	int i,j,k;
	if (x==1)for(i=0;i<n-1;i++){k=i;
	for(j=i+1;j<n;j++) if (a[k]>a[j]) k=j;
	swap(k,i);
	}
	if (x==0)for(i=0;i<n-1;i++){k=i;
	for(j=i+1;j<n;j++) if (a[k]<a[j]) k=j;
	swap(k,i);
	}
}
void exchangesort(int x){//x代表升序与否，升序为1，降序为0 
	int i,j;
	if (x==1) for(i=0;i<n-1;i++) for(j=i+1;j<n;j++)if (a[i]<a[j]) swap(i,j); 
	if (x==0) for(i=0;i<n-1;i++) for(j=i+1;j<n;j++)if (a[i]>a[j]) swap(i,j);
}
int searchs(int val){
	int i;
	for(i=0;i<n;i++) if (a[i]==val) return(i);return(-1);
}
int bisearch(int val){//升序降序都可以 
	int l=0,r=n-1,mid=(n-1)>>1;
	if (isasc){
	while (l<r) {
		if (a[mid]==val) return(mid);
		if (a[mid]>val){r=mid-1;mid=(l+r)>>1;}
		else {l=mid;mid=(l+r>>1);}
		}return(-1);
   }
	if (isdesc){
	while (l<r) {
		if (a[mid]==val) return(mid);
		if (a[mid]<val){r=mid-1;mid=(l+r)>>1;}
		else {l=mid;mid=(l+r>>1);}
		}return(-1);
   }
}
int leftrotate(int m){
	int i;
	for (i=0;i<m;i++) a[i+n]=a[i];
	n+=m;
	deleterange(0,m-1); 
}
int rightrotate(int m){
	leftrotate(n-m);
}
void josephus(int x){
    int i=0,pos,k=0;
  	for (pos=0;k<n;pos=(pos+1)%n){
  		if (a[pos]==0)i++;if (i==x){
  			i=0;k++;a[pos]=k;
		  }
	  }
}
void screen(int x,int y){

  int i,t;
  for(i=0;i<=y;i++) b[i]=0;  
  for (i=2;i<=y;i++) if (b[i]==0) {
  	t=2*i;while(t<=y) {
	  b[t]=1;t+=i;
  }
 }
  
   n=0;am=10;wi=4;
   for(i=x;i<=y;i++) if(b[i]==0){
   	a[n]=i;n++;
   }	
}
main(){
 while (ma1!=0) {
 	puts("");
 	puts("0、 退出");
 	puts("1、 配置系统参数");
	puts("2、 生成样本数据");
	puts("3、 显示数组");
	puts("4、 删除");
	puts("5、 插入");
	puts("6、 统计");
	puts("7、 查找");
	puts("8、 判断");
	puts("9、 排列数组元素");
	puts("10、数组的其他应用");
	puts("请先进行操作1和操作2再进行后续操作（操作10不需要先进行操作2）");
	puts("输入0将会退出当前菜单"); 
	puts("请输入操作指令");	
    puts("");
	scanf("%d",&ma1);puts("");
	if (ma1==1) {
		config();
	}
	if (ma1==2){
	  puts("  1） 用指定范围的随机数填充数组");
	  puts("  2） 键盘输入");
	  puts("  3） 整个数组填同一个值");
	  puts("  4） 用等差序列填充数组（注：输入序列的起始值和每项的差值）");
	  puts("  请输入操作指令");
	  puts("");
      scanf("%d",&ma2);puts("");
      if (ma2==1) {puts("请输入上限与下限");puts("");
	    scanf("%d%d",&x,&y);puts("");randomfill(y,x);} 
      if (ma2==2) read();
      if (ma2==3){puts("请输入该值");puts("");
	    scanf("%d",&x);puts("");fill(x);}
      if (ma2==4){puts("请输入起始值和差值");puts("");
	    scanf("%d%d",&x,&y);puts("");seqfill(x,y);}
	}
	if (ma1==3) printarr();
	if (ma1==4){
	  puts("  1） 删除指定下标的元素");
	  puts("  2） 删除指定值的元素");
	  puts("  3） 删除按指定下标区间的一组元素");
	  puts("  请输入操作指令");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {puts("请输入下标");puts("");scanf("%d",&x);puts("");deletes(x);} 
      if (ma2==2) {puts("请输入该值");puts("");scanf("%d",&x);puts("");search(x);
        while (searchs(x)!=-1){deletes(search(x));}
	  }
      if (ma2==3){puts("请输入区间上下界");puts("");
	    scanf("%d%d",&x,&y);puts("");deleterange(x,y);}  	
	}
	if (ma1==5){
	  puts("  1）按指定下标位置插入新元素");
	  puts("  2）在有序数组中插入新元素");	
	  puts("  请输入操作指令");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {puts("请输入下标和该元素");puts("");
	    scanf("%d%d",&x,&y);puts("");insert(x,y);} 
      if (ma2==2) {puts("请输入该值");puts("");
	    scanf("%d",&x);puts("");orderinsert(x);}
	}
	if (ma1==6){
	  puts("  1）求最大值");
	  puts("  2）求最小值");
	  puts("  3）求平均值");
	  puts("  4）求方差和均方差");
	  puts("  请输入操作指令");puts("");
      scanf("%d",&ma2);puts("");
      if (ma2==1)printf("最大值是%d\n",max());
      if (ma2==2)printf("最小值是%d\n",min());
	  if (ma2==3)printf("平均值是%.2f\n",average());
	  if (ma2==4)printf("方差和标准差分别是%.2f %.2f\n",variation(),deviation()); 
	}
	if (ma1==7){
	  puts("  1）普通查找");
	  puts("  2）二分查找（注：必须保证数组有序，如果无序请先排序）");
	  puts("  请输入操作指令");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {puts("请输入该值");puts("");scanf("%d",&x);puts("");
		if (search(x)!=-1) printf("该元素的下标为%d\n",search(x));
		  else puts("该元素不存在");} 
      if (ma2==2) {puts("请输入该值");puts("");
	    scanf("%d",&x);puts("");printf("该元素的下标为%d\n",bisearch(x));}	
	}
	if (ma1==8){
	  puts("  1）是否升序排列");
	  puts("  2）是否降序排列");
	  puts("  3）是否全部相等");
	  puts("  请输入操作指令");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1){if (isasc())puts("是");else puts("否");}
	  if (ma2==2){if (isdesc())puts("是");else puts("否");}
	  if (ma2==3){if (isequal())puts("是");else puts("否");}
	}
	if (ma1==9){
	  puts("  1）升序排序");
	  puts("  2）降序排序");
	  puts("  3）逆置数组");
	  puts("  4）左旋数组");
	  puts("  5）右旋数组");
	  puts("  请输入操作指令");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1){puts("    1.冒泡法 2.选择法 3.交换法");puts("");
	    scanf("%d",&ma3);puts("");
		if (ma3==1) bubblesort(1);
		if (ma3==2) selectsort(1);
		if (ma3==3) exchangesort(1); 
	  }
	  if (ma2==2){puts("    1.冒泡法 2.选择法 3.交换法");puts("");
	    scanf("%d",&ma3);puts("");
		if (ma3==1) bubblesort(0);
		if (ma3==2) selectsort(0);
		if (ma3==3) exchangesort(0);
	  }
	  if (ma2==3) reverse();
	  if (ma2==4){puts("输入左旋数");puts("");scanf("%d",&x);puts("");leftrotate(x);}
	  if (ma2==5){puts("输入右旋数");puts("");scanf("%d",&x);puts("");rightrotate(x);}
	}
	if (ma1==10){
	  puts("  1）约瑟夫环");
	  puts("  2）筛法求素数");
	  puts("  请输入操作指令");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {
	  	puts("请输入总人数和报数间隔");puts("");scanf("%d%d",&n,&x);puts("");
		 fill(0);josephus(x);printf("应该排在%d\n",search(n)+1);puts(""); 
	  }
	  if (ma2==2) {puts("请输入素数上下限");puts("");scanf("%d%d",&x,&y);puts("");
	  screen(x,y);puts("素数表已存在数组，请进行后续操作"); 
	  }
	} 
	} 	
}
