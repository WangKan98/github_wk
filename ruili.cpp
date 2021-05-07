// ruili.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define pi 3.1415

int main()
{
    int azi_num = 10000;//雷达回波帧数, 一帧表示一个重复周期
    int fr = 1000;//脉冲重复频率
    double lamda0 = 0.05;//波长
    double sigmav = 1.0;
    double sigmaf = 2 * sigmav / lamda0;
    // rand('state', sum(100 * clock));
    srand((unsigned)time(NULL));
    //d1 = rand(1, azi_num);
    double d1 = 1 + rand() % azi_num;
    //rand('state', 7 * sum(100 * clock) + 3);
    srand((unsigned)time(NULL) * 7);
    double d2 = 1 + rand() % azi_num;
    double xi = 2 * sqrt(-2 * log(d1)) * cos(2 * pi * d2);//正交且独立的高斯序列N（0，1）
    double xq = 2 * sqrt(-2 * log(d1)) * sin(2 * pi * d2);
    int coe_num = 12;// 用傅里叶级数展开法求滤波器系数
    //for n = 0:coe_num;
    for (int n = 0; n < coe_num; n++)
    {
        //coeff(n + 1) = 2 * sigmaf * sqrt(pi) * exp(-4 * sigmaf ^ 2 * pi ^ 2 * n ^ 2 / fr ^ 2) / fr;
        //end
        for (int m = 1; m < 2 * coe_num + 1; m++)
        {
            if (m <= coe_num + 1)
            {
                //  b(m) = 1 / 2 * coeff(coe_num + 2 - m);
            }
            else {
                // b(m) = 1 / 2 * coeff(m - coe_num);
            }
        }
        // end
      //  end
 /*     xxi = conv(b, xi);% 一维卷积运算
        xxq = conv(b, xq);% 一维卷积运算
        xxi = xxi(coe_num * 2 + 1:azi_num + coe_num * 2);% 目的是去掉暂态响应（貌似卷积之后应该很重要的一步）
        xxq = xxq(coe_num * 2 + 1:azi_num + coe_num * 2);
        xisigmac = std(xxi); % 求标准差
        ximuc = mean(xxi); % 求均值
        yyi = (xxi - ximuc) / xisigmac; % 标准化，为了后面的功率谱比较
        xqsigmac = std(xxq);
        xqmuc = mean(xxq);
     yyq = (xxq - xqmuc) / xqsigmac;
    sigmac = 1.2;% 杂波的标准差
        yyi = sigmac * yyi;% 使瑞利分布杂波具有指定的标准差
        yyq = sigmac * yyq;
    % j = sqrt(-1);
    ydata = yyi + j * yyq;
    subplot(2, 2, 2)
        plot(abs(ydata))
        title('瑞利分布杂波');
    % xlabel('b');
    num = 100;% 求概率密度函数的参数
        maxdat = max(abs(ydata));
    mindat = min(abs(ydata));
    NN = hist(abs(ydata), num);
    xpdf1 = num * NN / ((sum(NN)) * (maxdat - mindat)); % 幅度分布
        xaxis1 = mindat:(maxdat - mindat) / num : maxdat - (maxdat - mindat) / num; % 横坐标
        th_va1 = (xaxis1. / sigmac ^ 2).*exp(-xaxis1. ^ 2. / (2 * sigmac ^ 2));% 概率密度函数理论值
        subplot(2, 2, 3), plot(xaxis1, xpdf1);% 作出仿真结果的概率密度函数曲线
        hold, plot(xaxis1, th_va1, ':r');% 作出理论概率密度函数曲线
        title('杂波的幅度分布');
    xlabel('杂波的幅度')
        ylabel('概率密度')
        signal = ydata;
    signal = signal - mean(signal);% 求功率谱密度，先去掉直流分量 到中心
        %%%% 用burg法来估计功率谱密度%%%%%
        M = 256;
    psd_dat = pburg(signal, 32, M, fr);
    whos psd_dat
        psd_dat = psd_dat / (max(psd_dat));% 归一化处理
        psd_dat = [psd_dat(126:256)',psd_dat(1:125)']';
        % freqx = 0:0.5 * M;
    freqx = -0.5 * M:1 : 0.5 * M - 1
    freqx = freqx * fr / M;*/
    }