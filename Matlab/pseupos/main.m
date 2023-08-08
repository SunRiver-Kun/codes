%��ȡ���ݣ����뵥λΪm
clear;clc;
[ stapos,satpos,p ] = ImportData('output.txt');

%ͨ��������ת����satpos 
%������ת���ٶ� w = 15��/h = 7.27*1E-5 rad/s   �����������������0.06s-0.1s
theta = 0.06 * 7.27*1E-5;
correct_satpos = [cos(theta),sin(theta),0;-sin(theta),cos(theta),0;0,0,1];
for i = 1:8
    satpos(i,:) = (correct_satpos*satpos(i,:)')';
end

%����α�����ֵ
p0 = zeros(8,1);
for i = 1:8
    p0(i,1)=norm(satpos(i,:)-stapos);
end

%��ʼ������
xyzt=[0 0 0 0];  %X0 Y0 ...
B = zeros(8,4);
L = zeros(8,1);
B(:,4) = B(:,4)-1;   %��B���һ��Ϊ-1

for i = 1:1000  
    for j = 1:8 
        B(j,1:3) = (xyzt(1:3)-satpos(j,:))/norm(xyzt(1:3)-satpos(j,:));
        L(j,1) = p(j,1) - norm(xyzt(1:3)-satpos(j,:));  %ģ�͸���Ϊ0
    end
    delta = (B'*B)\(B'*L);  %PȨ��Ĭ��ΪE�� <--> (BT*B)-1 * (BT*L)
    xyzt = xyzt + delta';
    accuracy=norm(delta);   %��λ����
    if (accuracy<1e-10)
        break;
    end
end

disp('��������')
i
disp('�����ϵĻ�վλ��Ϊ')
stapos
disp('����õĻ�վλ��Ϊ')
xyzt(1:3)
disp('�����ǵ�α�� ���۾���')
compare = [p,p0]