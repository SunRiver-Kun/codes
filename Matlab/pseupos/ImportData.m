function [ stapos,satpos,p ] = ImportData(path)
%IMPORTDATA 导入我们的文件。
% stapos基站位置  satpos卫星位置  p伪距
%path = 'output.txt'
[f,message] = fopen(path,'r');
if f==-1,
    disp(message)
end
A = fscanf(f,'%lf',[4,9]);
B = transpose(A);
stapos = B(1,[1,2,3]);
satpos = B([2:9],[1,2,3]);
p = B([2:9],4);
end
