1. プログラムとその説明

- コード
```py
import cv2
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

img1=cv2.imread('digi1.jpg',0)
img2=cv2.imread('digi2.jpg',0)
img3=cv2.imread('digi3.jpg',0)
img4=cv2.imread('digi4.jpg',0)

imave1=np.mean(img1)
imave2=np.mean(img2)
imave3=np.mean(img3)
imave4=np.mean(img4)

ylist=[imave1, imave2, imave3, imave4]

print(ylist)

xlist=[1, 2, 3, 4]
plt.xticks([1, 2, 3, 4])
plt.plot(xlist, ylist, 'o')
plt.xlabel("Number of pictures")
plt.ylabel("Average of luminance")
plt.show()
```

- プログラムの説明  
   1. cv2, numpy, PIL, matplotlib.pyplotを読み込む
   2. カレントディレクトリ内にある、画像ファイルdigi1.jpg ~ digi4.jpgをimg1 ~ img4に読み込む
   3. imave1 ~ imave4にそれぞれの輝度値の平均を代入する
   4. ylistにそれらを格納、print
   5. xlistと、plt.xticksでグラフでx軸に使う画像番号を準備、整形
   6. plt.plotでグラフにプロット(オプション'o'で小さい青丸の点で表示)
   7. 軸ラベルなどの設定

2. 使い方，実行の仕方，依存ライブラリとバージョン

    - 使い方・実行の仕方
        - digital.ipynbダウンロードし、jupyter notebookを起動。ctrl+Enterで実行(カレントディレクトリにあらかじめファイル名 digi1.jpg ~ digi4.jpgを用意しておく)
    - 依存ライブラリとバージョン  
        - opencv-python　　4.1.0.25  
        - numpy　　1.16.4  
        - matplotlib　　3.1.0  
        - pillow　　6.1.0

   - 参考にしたサイトなどへのリンク  
     - 「Qiita」matplotlibでのプロットの基本  
     https://qiita.com/KntKnk0328/items/5ef40d9e77308dd0d0a4  
       
        参考箇所・・・プロットのマーカー指定
     - 「Qiita」matplotlib によるデータ可視化の方法 (2)  
     https://qiita.com/ynakayama/items/aec4e962d738d24641ee  
     
        
        参考箇所・・・目盛り、ラベル  

    3. 実行の様子
    ![1](\digital.gif)