package com.Miautawn;

// a simple hello world program for that Hacktober mood going :)
/* How to use:
1. Type anything you want
2. Profit

Enjoy, made by Miautawn
 */

import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Main {

    public static void main(String[] args) {
        String[] Password = new String[4];
        Scanner scan = new Scanner(System.in);

        System.out.println("Welcome to Hacktober! Please write your secret pass ID: ");
        Password[0] = scan.next();
        Decode("Decoding...", 2);
        System.out.println("Confirmed! Please write your encoded password");
        Password[1] = scan.next();
        Decode("Searching for patterns...", 1);
        System.out.println("Done! Authentication is successful! Now please write THE ANSWER");
        Password[2] = scan.next();
        Decode(":+90q8qq42=<<>q1", 2);
        System.out.println(Password[2] + " It is! Now for the final Question: write your Name!");
        Password[3] = scan.next();
        Decode("You are truly the Hactober participant!", 1);
        System.out.println("Hello World and Hello to you " + Password[3]);
    }

    public static void Decode(String message, int time)
    {
        System.out.println(message);
        try
        {
            TimeUnit.SECONDS.sleep(time);
        }
        catch (InterruptedException ex)
        {
            System.out.println("System Breach! Exiting...");
            System.exit(0);
        }
    }
}