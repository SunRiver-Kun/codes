1. 先使用ReadData.exe读取文件数据，生成 output.txt 供matlab使用
2. 打开matlab运行main.m，如果关联有matlab，双击.m即可

注：由于21o和sp3文档比较复杂，用matlab读取不方便，所有我直接用C++来读取了。

output格式
基站X	Y	Z	0（补位）
卫星1X      Y	Z	伪距1
卫星2X      Y	Z	伪距2
...
卫星8X      Y	Z	伪距8
