%读取数据，距离单位为m
clear;clc;
[ stapos,satpos,p ] = ImportData('output.txt');

%通过地球旋转改正satpos 
%地球自转角速度 w = 15°/h = 7.27*1E-5 rad/s   卫星数据下来大概是0.06s-0.1s
theta = 0.06 * 7.27*1E-5;
correct_satpos = [cos(theta),sin(theta),0;-sin(theta),cos(theta),0;0,0,1];
for i = 1:8
    satpos(i,:) = (correct_satpos*satpos(i,:)')';
end

%理想伪距测量值
p0 = zeros(8,1);
for i = 1:8
    p0(i,1)=norm(satpos(i,:)-stapos);
end

%初始化参数
xyzt=[0 0 0 0];  %X0 Y0 ...
B = zeros(8,4);
L = zeros(8,1);
B(:,4) = B(:,4)-1;   %让B最后一列为-1

for i = 1:1000  
    for j = 1:8 
        B(j,1:3) = (xyzt(1:3)-satpos(j,:))/norm(xyzt(1:3)-satpos(j,:));
        L(j,1) = p(j,1) - norm(xyzt(1:3)-satpos(j,:));  %模型改正为0
    end
    delta = (B'*B)\(B'*L);  %P权阵默认为E了 <--> (BT*B)-1 * (BT*L)
    xyzt = xyzt + delta';
    accuracy=norm(delta);   %定位精度
    if (accuracy<1e-10)
        break;
    end
end

disp('迭代次数')
i
disp('星历上的基站位置为')
stapos
disp('计算得的基站位置为')
xyzt(1:3)
disp('各卫星的伪距 理论距离')
compare = [p,p0]