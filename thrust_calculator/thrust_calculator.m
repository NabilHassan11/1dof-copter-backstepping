clc
clear all
h.f=0;
h.thrust=0;
h.arr=1;
h.arduino=serial('COM22','baud',115200);
try
    fopen(h.arduino);
    
catch e
    errordlg(e.message);
    fclose(h.arduino);
end
% [front rear right left]
for motorsignal=1000:50:2000
    h.f=motorsignal;
    h.f_array(h.arr)=h.f;
    tosend=horzcat('5',' ','1000',';','1000',';','1000',';',num2str(h.f),';','6');
%     tosend=horzcat('5',' ','1000',';','1000',';',num2str(h.f),';','1000',';','6');
%     tosend=horzcat('5',' ','1000',';',num2str(h.f),';','1000',';','1000',';','6');
%     tosend=horzcat('5',' ',num2str(h.f),';','1000',';','1000',';','1000',';','6');
    
    fprintf(h.arduino,tosend);
    % ---Counterchecking the sent commands
    sent=fgetl(h.arduino)
    pin=0.124*motorsignal+2
    h.thrust=input('thrust in grams = ');
    h.thrust_array(h.arr)=h.thrust;
    h.arr=h.arr+1;
end
tosend=horzcat('5',' ','1000',';','1000',';','1000',';','1000',';','6');
fprintf(h.arduino,tosend);
tosend=horzcat('5',' ','0',';','0',';','0',';','0',';','6');
fprintf(h.arduino,tosend);
fclose(h.arduino);
figure
plot(h.f_array,h.thrust_array);
title('Thrust in grams vs Motor signal');
axis([1000 2000 0 2000]);