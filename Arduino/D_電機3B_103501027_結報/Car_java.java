package com.j204_1.han.bluetoothabbcar;

import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.os.Message;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;

import tw.com.flag.api.FlagBt;
import tw.com.flag.api.FlagTank;
import tw.com.flag.api.OnFlagMsgListener;

public class MainActivity extends AppCompatActivity implements OnFlagMsgListener {
    FlagBt bt;
    TextView txv;
    FlagTank tank;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.setRequestedOrientation(  //讓手機螢幕保持橫向模式
                ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
        txv = (TextView)findViewById(R.id.txv);
        bt = new FlagBt(this); // 建立藍牙物件
        tank=new FlagTank(bt); // 建立Tank物件
    }
    public void onDestroy() {
        bt.stop(); // 確保程式結束前會停止藍牙連線
        super.onDestroy();
    }
    public void connect(View v) {
        if(!bt.connect()) // 選取已配對裝置進行連線
            txv.setText("找不到任何已配對裝置");
    }
    public void quit(View v) {
        bt.stop();
        finish();
    }
    @Override
    public void onFlagMsg(Message msg) {
        switch (msg.what) {
            case FlagBt.CONNECTING: // 嘗試與已配對裝置連線
                txv.setText("正在連線到：" + bt.getDeviceName());
                break;
            case FlagBt.CONNECTED:  // 與已配對裝置連線成功
                txv.setText("已連線到：" + bt.getDeviceName());
                break;
            case FlagBt.CONNECT_FAIL: // 連線失敗
                txv.setText("連線失敗！請重連");
                break;
            case FlagBt.CONNECT_LOST: // 目前連線意外中斷
                txv.setText("連線中斷!請重連");
                break;
        }
    }
    // 定義藍芽資料傳送
    public  void ForwardLeft(View v){bt.write("G");}
    public  void Forward(View v){bt.write("F");}
    public  void ForwardRight(View v){bt.write("I");}
    public  void Left(View v){bt.write("L");}
    public  void Stop(View v){bt.write("S");}
    public  void Right(View v){bt.write("R");}
    public  void BackLeft(View v){bt.write("H");}
    public  void Back(View v){bt.write("B");}
    public  void BackRight(View v){bt.write("J");}
}