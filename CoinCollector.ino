import com.phidget22.*;
import com.phidget22.UnitInfo;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.layout.HBox;
import javafx.event.ActionEvent;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;
import javafx.geometry.*;
import javax.swing.JOptionPane;

import java.net.URL;

import java.lang.Object;
import java.io.File;

import java.util.Scanner;
import java.lang.Object;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.layout.Region;
import javafx.scene.control.Control;
import javafx.scene.control.TextInputControl;
import javafx.scene.control.TextField;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.*;

import java.text.NumberFormat;

import javafx.scene.layout.*;

import javafx.stage.Stage;
import javafx.geometry.*;

import javax.swing.*;
import java.awt.event.*;

import javafx.application.Platform;

import java.lang.Object;

import java.io.*;

import java.util.Locale;


 public class CoinCollector extends Application //implements VoltageRatioInputVoltageRatioChangeListener
{
   //public static VoltageRatioInputVoltageRatioChangeListener onVoltageRatioChange = new VoltageRatioInputVoltageRatioChangeListener();
   private VoltageRatioInput sensorRotate1;
   private VoltageRatioInput sensorRotate2;
   private VoltageRatioInput sensorRotate3;
   private VoltageRatioInput sensorRotate4;
   private RCServo servo;
   private int penny;
   private String returnInDollars;
   private int nickel;
   private int dime;
   private int quarter;
   private static int quart;
   private static int pen;
   private static int di;
   private static int nic;
   private static int r;
   private double totalCalc;
   private double calcPenny;
   private double calcNickel;
   private double calcDime;
   private double calcQuarter;
   private int x;
   private int ended = 0;
   private int count;
   private LCD lcd;
   
   
   @Override
   public void start(Stage stage) throws Exception

   {
 
       servo = new RCServo();
      servo.setDeviceSerialNumber(45457);
      servo.setChannel(0);
     
 

      sensorRotate1 = new VoltageRatioInput();
      sensorRotate1.setDeviceSerialNumber(95958);
      sensorRotate1.setChannel(1);
      sensorRotate1.open(5000);  
      sensorRotate1.setVoltageRatioChangeTrigger(0.1);

     
      sensorRotate2 = new VoltageRatioInput();
      sensorRotate2.setDeviceSerialNumber(95958);
      sensorRotate2.setChannel(2);
      sensorRotate2.open(5000);  
      sensorRotate2.setVoltageRatioChangeTrigger(0.1);
     
      sensorRotate3 = new VoltageRatioInput();
      sensorRotate3.setDeviceSerialNumber(95958);
      sensorRotate3.setChannel(3);
      sensorRotate3.open(5000);  
      sensorRotate3.setVoltageRatioChangeTrigger(0.1);

      sensorRotate4 = new VoltageRatioInput();
      sensorRotate4.setDeviceSerialNumber(95958);
      sensorRotate4.setChannel(4);
      sensorRotate4.open(5000);  
      sensorRotate4.setVoltageRatioChangeTrigger(0.1);
     
      playSound();
      onVoltageRatioChange(stage);

           
     
   }
   public void ServoX(int x) throws Exception
   {
      if(x ==1)
      {
         servo.open(5000);  
         servo.setTargetPosition(0);
         servo.setEngaged(true);

      }
      else if( x ==2)
      {
         servo.open(5000);  
         servo.setTargetPosition(60);
         servo.setEngaged(true);

      }
      else if(x==3)
      {
         servo.open(5000);  
         servo.setTargetPosition(120);
         servo.setEngaged(true);

      }
      else if(x == 4)
      {
         servo.open(5000);  
         servo.setTargetPosition(180.0);
         servo.setEngaged(true);

      }
      else
      {
         System.out.println("You didn't enter a correct coin");
           servo.open(5000);  
         servo.setTargetPosition(180.0);
         servo.setEngaged(true);
      }
   }
   public void LCDX() throws Exception
   {
      LCD lcd = new LCD();
      lcd.setDeviceSerialNumber(120864);
lcd.setHubPort(0);
lcd.setIsHubPortDevice(false);
lcd.setChannel(0);    
      lcd.open(5000);
       
      double f = lcd.getMaxBacklight();
      lcd.setBacklight(f);
     
      lcd.writeText(LCDFont.DIMENSIONS_5X8, 0, 0, "P:" + penny + " Q: " + quarter + " D:" + dime + " N:" + nickel);
    //  lcd.writeText(LCDFont.DIMENSIONS_5X8, 0, 1,"$" + returnInDollars);
  lcd.flush();

  Thread.sleep(5000);
      lcd.close();
     

   }
   public void coins(Stage stage) throws Exception
   {
      TextField pe = new TextField();
      TextField ni = new TextField();
      TextField dim = new TextField();
      TextField qu = new TextField();
     
     
     
      GridPane gridPane = new GridPane();
      if(x ==1)
      {
         Label pennies = new Label("Pennies");
         gridPane.add(pennies,0,0);
         gridPane.add(pe,0,1);

      }
      else if(x ==2)
      {
         Label nickles = new Label("Nickles");
         gridPane.add(nickles,0,0);
         gridPane.add(ni,0,1);
      }
      else if(x==3)
      {
         Label dimes = new Label("Dimes");
          gridPane.add(dimes,0,0);
         gridPane.add(dim,0,1);
      }
      else if( x ==4)
      {
         Label quarters = new Label("Quarters");
         gridPane.add(quarters,0,0);
         gridPane.add(qu,0,1);

      }

     
      Button button = new Button("Increase");
      Button closer = new Button("Close window");
      Button ender = new Button("End Program");
      Button reset = new Button("Reset Count");
     

      gridPane.add(button,1,0);
      gridPane.add(closer,1,1);
      gridPane.add(ender,1,2);
      gridPane.add(reset,1,3);
     
      Scene scene = new Scene(gridPane, 320, 300);        
      stage.setTitle("How many coins did you just and and which ones?");
      stage.setScene(scene);
      stage.show();
     
      reset.setOnAction(u ->{
         r=1;
         try
         {
            resetCoin();
            ended++;
            System.exit(0);
         }
         catch(Exception o)
         {
            System.out.println("There is an error resetting the coins:" + o.getMessage());
         }
      });
     
      button.setOnAction(l ->{
         try
         {
            if(x == 1)
            {
               pen += Integer.parseInt(pe.getText());
            }
            else if( x ==2)
            {
                nic += Integer.parseInt(ni.getText());
            }
            else if (x ==3)
            {
               di += Integer.parseInt(dim.getText());
            }
            else if (x==4)
            {
               
               quart += Integer.parseInt(qu.getText());
            }
            else
               System.out.println("Nothing was added");
         }
         catch(Exception e)
         {
            System.out.println("There is an error:" +e.getMessage());
         }
      });
     
      closer.setOnAction(e ->{
         stage.close();
           
         try
         {
           
            fileWriter();
           // calculation();
            LCDX();
         }
         catch(Exception i)
         {
            System.out.println("LCD error:" +i.getMessage());
         }
      });
      ender.setOnAction(y ->{
      ended++;
      System.exit(0);
      });
 
     
     
   }
   public void calculation()
   {
      calcPenny = penny *.01;
      calcNickel = nickel*.05;
      calcDime = dime*.1;
      calcQuarter = quarter*.25;
     
      totalCalc = calcPenny+calcNickel+calcDime+calcQuarter;
      System.out.print(totalCalc);
      if(totalCalc > 100)
      {
      NumberFormat n = NumberFormat.getCurrencyInstance(Locale.US);
      returnInDollars = n.format(totalCalc / 100.0);
     
      }
     
   }
   public void currentTotal(Stage stage)
   {
      Label totalPennies = new Label("Total Pennies");
      Label totalQuarters = new Label("Total Quarters");
      Label totalNickles = new Label("Total Nickles");
      Label totalDimes = new Label("Total Dimes");
     
      Label pennies = new Label(Integer.toString(pen));
      Label quarters = new Label(Integer.toString(quart));
      Label nickles = new Label(Integer.toString(nic));
      Label dimes = new Label(Integer.toString(di));
     
      Button closeing = new Button("Click to close");
     
      GridPane gridPane = new GridPane();
     
      gridPane.add(totalPennies,0,0);
      gridPane.add(totalNickles,1,0);
      gridPane.add(totalDimes,2,0);
      gridPane.add(totalQuarters,3,0);
     
      gridPane.add(pennies,0,1);
      gridPane.add(nickles,1,1);
      gridPane.add(dimes,2,1);
      gridPane.add(quarters,3,1);
     
      Scene scene = new Scene(gridPane, 320, 300);        
      stage.setTitle("Current amount of how many coins there are");
      stage.setScene(scene);
      stage.show();
     
      closeing.setOnAction(e ->{
      stage.close();      
      });
      count++;
   }
   

   
   public void onVoltageRatioChange(Stage stage) throws Exception
   {
      try
      {
     
               long startTime = System.currentTimeMillis(); //fetch starting time
                  while((System.currentTimeMillis()-startTime)<5000)
                  {
                     if(sensorRotate1.getVoltageRatio()>0.7)
                     {
                     
                         x = 1;
                                       
                     }
                     else if(sensorRotate2.getVoltageRatio()>0.7)
                     {
                         x = 2;
                     
                     }
                     else if(sensorRotate3.getVoltageRatio()>0.7)
                     {
                         x = 3;
                       
                     }
                     else if(sensorRotate4.getVoltageRatio()>0.7)
                     {
                         x = 4;
                     
                     }
                  }
                  ServoX(x);
                 
                  coins(stage);
                 
       }
       catch(Exception err)
       {
         System.out.println("There is an error:" + err.getMessage());
       }
   }
   public void fileWriter() throws Exception
   {
   
   
      PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("the-file-name.txt", true)));
      File file = new File("the-file-name.txt");
      Scanner scan = new Scanner(file);
     /* writer.println(0);
      writer.println(0);
      writer.println(0);
      writer.println(0);
      writer.close();*/
     
     
 
      penny = pen + Integer.parseInt(scan.nextLine());
      nickel = nic + Integer.parseInt(scan.nextLine());
      dime = di+ Integer.parseInt(scan.nextLine());
      quarter = quart+ Integer.parseInt(scan.nextLine());
     
         
      PrintWriter writer2 = new PrintWriter("the-file-name.txt","UTF-8");
     
     
      writer2.println(Integer.toString(penny));
      writer2.println(Integer.toString(nickel));
      writer2.println(Integer.toString(dime));
      writer2.println(Integer.toString(quarter));
      writer2.close();
     
   
     
      //catch(Exception v)
      //{
        // System.out.println("Error with adding to file " + v.getMessage());
      //}
   }
   public void resetCoin() throws Exception
   {
        if(r>0)
      {
         PrintWriter writer3 = new PrintWriter("the-file-name.txt","UTF-8");
         writer3.println(Integer.toString(0));
         writer3.println(Integer.toString(0));        
         writer3.println(Integer.toString(0));
         writer3.println(Integer.toString(0));
         writer3.close();
         System.out.println("The coins have been reset");
      }
   }
   public void playSound()
   {
      final URL resource = getClass().getResource("CoinDropSound.wav");
      final Media media = new Media(resource.toString());
      final MediaPlayer mediaPlayer = new MediaPlayer(media);
      mediaPlayer.play();

   }
   public static void main(String[] args)
   {
      // add flag and listener here
      launch(args);
   }  
}
