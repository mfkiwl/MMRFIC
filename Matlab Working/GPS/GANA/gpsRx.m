%% Function to create the Tx signal for the given list of SVs
%%
%% (C) MMRFIC Technology Pvt. Ltd., Bangalore INDIA
%%---------------------------------------------------------------
%% Usage:
%% function [txSignal, payload, hFilt, codeOffsetArray, freqOffsetArray, symbol] = gpsTx(svIdArray, numBits, OSR, alpha)
%%
%% Version History: (in reverse chronological order please)
%%
%% ver  0.1   10-Jan-2020   Sudhanshu             Created

%% changes made:
%% line 56 gpsTx.m
%% Sending goldcode with gpsTx()
%% currently with no codeOffset only with FreqOffsetArray.

clc;
clear all;
close all;

[txSignal, payload, hFilt, codeOffsetArray, freqOffsetArray,symbol] = gpsTx();

%% Adding Noise
snr = -26;
txSignal = awgn(txSignal,snr);

%% Reciever
codeLen = 1023;
OSR = 10;
Fs = OSR*1e6;
J = sqrt(-1);
hFiltLen = length(hFilt);
[numSVs,lengthtx] =size(txSignal);
% RxData = zeros(201,numSVs);
% crossCorrData = zeros((lengthtx/10)+60,numSVs);
for nSV = 1:numSVs
    temp1 = txSignal(nSV,:);
    tx = temp1.*exp(J*(-1)*2*pi*freqOffsetArray(nSV)/Fs*[0:lengthtx-1]);
    tx = real(tx);
    downsamtx = downsample(tx,OSR);
    downsamtx_hfilt = conv(downsamtx,hFilt);
    downsamtx_hfilt = downsamtx_hfilt((hFiltLen-1)/2+1:end-(hFiltLen-1)/2);
    crossCorr = xcorr2(downsamtx_hfilt,symbol(nSV,:));
    outputData = crossCorr(1023:codeLen:end)/codeLen;
    % RxData(:,nSV) = outputData;
    % plot(outputData)
    % crossCorrData(:,nSV) = crossCorr;
end

%% Plotting avg value
avgValue = zeros(10);
val = 0;
lastval = 0;
for i =1:20:length(outputData)
    lastval = lastval+20;
    avg = sum(outputData(i:1:lastval));
    val = val +1;
    avgValue(val)=avg;
end
stem(avgValue)