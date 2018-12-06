package com.bug.ideas.cc;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;

import com.bug.ideas.crash.lib.CrashCatch;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText("测试崩溃");
        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                CrashCatch.foo();
            }
        });
    }

}
