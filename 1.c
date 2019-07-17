#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 4 // 変数の個数
#define L 2 // 条件式の数
#define M L+1 // タブローの全行数
#define N K+L+1 // タブローの全列数

// タブローの入力
void inputTab(double tab[M][N],int ids[L]){
  int i,j,k;
  double elm;
  
  // クリヤー
  for(i=0;i<M;i++) {
    for(j=0;j<N;j++) {
      tab[i][j] = 0.;
    }
  }
  // 目的関数の係数入力
  printf("目的関数：\n");
  for(j=0;j<K;j++) {
    printf(" 第%d変数の係数＞",j+1);
    scanf("%lf",&elm);
    tab[0][j] = -elm;
  }
  // 条件式の係数と定数の入力
  printf("条件式：\n");
  for(i=1;i<M;i++) {
    printf(" 第%d条件式の係数：\n",i);
    for(j=0;j<K;j++) {
      printf(" 第%d変数の係数＞",j+1);
      scanf("%lf",&tab[i][j]);
    }
    printf(" 第%d条件式の定数＞",i);
    scanf("%lf",&tab[i][N-1]);
  }
  // スラック単位行列
  for(i=1;i<M;i++) {
    for(j=K;j<N-1;j++) {
      tab[i][j] = 0.;
    }
    tab[i][K+i-1] = 1.;
  }
  // スラック変数idの登録
  for(k=0;k<L;k++) {
    ids[k] = K+k+1;//@
  }
  return;
}
// タブローの表示
void printTab(double tab[M][N],int ids[L]){
  int i,j;

  printf("シンプレックス表：( ) は変数の番号\n");
  for(i=0;i<M;i++) {
    for(j=0;j<N;j++) {
      printf(" %6.3f",tab[i][j]);
    }
    if( i==0 ) printf("\n");
    else printf(" (%d)\n",ids[i-1]);
  }
  return;
}
// 変数列の第１行で最小列を探す→kmin(-1; not found)
int srchnxt(double target[K]){
  int jvar,kmin;
  double maxv;

  kmin = -1;
  for(maxv=jvar=0;jvar<K;jvar++) {
    if(fabs(target[jvar]) > maxv ) {
      maxv = fabs(target[jvar]);
      kmin = jvar;
    }
  }
  return kmin;
}
// 選んだ変数列の中で行を選ぶ
int select(int jvar,double tab[M][N],int ids[L]){
  int icon;
  double tstv;
  double minv;
  int jmin;

  for(icon=1;icon<M;icon++) {
    tstv = tab[icon][N-1]/tab[icon][jvar];
    if( icon==1 ) {
      minv = tstv;
      jmin = icon;
    } else {
      if(tstv<minv) {
    minv = tstv;
    jmin = icon;
      }
    }
  }
  ids[jmin-1] = jvar+1;//@
  return jmin;
}
// 変数(jvar)の第(icon)条件をピボットとして消去
int reduce(double tab[M][N],int icon,int jvar) {
  int i,j;
  double pivot,ipv;

  pivot = tab[icon][jvar];
  if( pivot == 0 ) return 1;
  for(j=0;j<N;j++) {
    tab[icon][j] /= pivot;
  }
  for(i=0;i<N;i++) {
    if( i==icon ) continue;
    ipv = tab[i][jvar];
    for(j=0;j<N;j++) {
      tab[i][j] -= ipv*tab[icon][j];
    }
  }
  return 0;
}
// シンプレックス法
int simplex(double tab[M][N],int ids[L]){
  int icon,jvar,kerr;
  int k;
  while( (jvar=srchnxt(tab[0])) >= 0 ) {
    icon = select(jvar,tab,ids);
    kerr=reduce(tab,icon,jvar);
    printTab( tab,ids );
    if( kerr ) {
      printf("ピボット縮退のため中止。\n");
      return 1;
    }
  }
  printf("シンプレックス解\n");
  for(k=1;k<=K;k++) {
    printf("変数 (%d): %6.3f\n",ids[k-1],tab[k][N-1]);
  }
  printf("目的関数: %6.3f\n",tab[0][N-1]);
  return 0;
}
int main(){
  double tab[M][N];
  int ids[L];

  inputTab( tab,ids );
  printTab( tab,ids );
  simplex ( tab,ids );
  return 0;
}