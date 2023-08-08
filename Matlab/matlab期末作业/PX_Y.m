function varargout = PX_Y(varargin)

% Name：二维正态分布
% Author：测绘1901杨荣坤
% Time：2020.10.14

gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @PX_Y_OpeningFcn, ...
                   'gui_OutputFcn',  @PX_Y_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end


% Load
function PX_Y_OpeningFcn(hObject, eventdata, handles, varargin)
handles.output = hObject;
guidata(hObject, handles);

%   自定义数据  20 0.1 0.99
handles.Opc1.UserData = 20;
handles.Opc2.UserData = 0.1;
handles.Opc3.UserData = 0.99;

%初始化
handles.myslider.Min = 0.1;
handles.myslider.Max = 20;
handles.myslider.Value = 20 %对应选项1的

[x,y] = meshgrid([-10:0.1:10],[-20:0.1:20]); 
Q =  ( (x/handles.Opc1.UserData).^2 - 2*handles.Opc3.UserData*(x/handles.Opc1.UserData).*(y/handles.Opc2.UserData) + (y/handles.Opc2.UserData).^2 )/(1-handles.Opc3.UserData^2);
f = exp(-Q/2)/(2*pi*handles.Opc1.UserData*handles.Opc2.UserData*sqrt(1-handles.Opc3.UserData^2));
mesh(x,y,f);



% --- Outputs from this function are returned to the command line.
function varargout = PX_Y_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


%选项1
function Opc1_Callback(hObject, eventdata, handles)
handles.myslider.Min = 0.1;
handles.myslider.Max = 20;
handles.myslider.Value = hObject.UserData;
handles.text1.String = 'σ1 =';
set(handles.text2,'String',num2str(hObject.UserData));


%选项2
function Opc2_Callback(hObject, eventdata, handles)
handles.myslider.Min = 0.1;
handles.myslider.Max = 20;
handles.myslider.Value = hObject.UserData;
handles.text1.String = 'σ2 =';
set(handles.text2,'String',num2str(hObject.UserData));
%选项3
function Opc3_Callback(hObject, eventdata, handles)
handles.myslider.Min = -0.99;
handles.myslider.Max = 0.99;
handles.myslider.Value =  hObject.UserData;
handles.text1.String = 'p =';
set(handles.text2,'String',num2str(hObject.UserData));

%滚动条，每滑动一次就重画一次
function myslider_Callback(hObject, eventdata, handles)
%错误记录：  handles.text2.String = num2str( get(handles.myslider,'Value')) ;
set(handles.text2,'String',num2str(hObject.Value));
%或 set(handles.text2,'String',num2str( get(handles.myslider,'Value') ));
%按钮组，只有一个Value==1,其他为0
if handles.Opc1.Value==1,
    handles.Opc1.UserData = hObject.Value;
elseif handles.Opc2.Value == 1,
    handles.Opc2.UserData = hObject.Value;
else
    handles.Opc3.UserData = hObject.Value;
end
[x,y] = meshgrid([-10:0.1:10],[-20:0.1:20]); 
Q =  ( (x/handles.Opc1.UserData).^2 - 2*handles.Opc3.UserData*(x/handles.Opc1.UserData).*(y/handles.Opc2.UserData) + (y/handles.Opc2.UserData).^2 )/(1-handles.Opc3.UserData^2);
f = exp(-Q/2)/(2*pi*handles.Opc1.UserData*handles.Opc2.UserData*sqrt(1-handles.Opc3.UserData^2));
mesh(x,y,f);
