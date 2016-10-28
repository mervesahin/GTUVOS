#ifndef MAILSERVER_H
#define MAILSERVER_H

#include <string>

using std::string;


class MailServer{
public:
    /**
    * Default Constructors
    *
    * -Check MailServer Directory
    * -Check the mailArchive file
    */
    MailServer();

    /**
    * Virtual Constructors
    */
    virtual ~MailServer();

    /**
    * Run MailServer
    *
    * -Set "widget" variable
    * -Set "isItClosed" variable true
    * -Call the readInput function for read input from the terminal
    */
    void runMailServer();

    /**
     * This function is read input from the terminal
     *
     * -Read input from the terminal
     * -Call the parseString function
     * -If "isItClosed" variable true then wait the next input.
     * -if "isItClosed" variable false then interrupt loop
     */
    void readInput();

    /**
     * This function parses the newString, then calls the appropriate function
     *
     * -parse the newString
     * -if newString is meaningful then call the appropriate command
     * -if newString is not meaningful then call the function
     * "writeGivenStringOnTheScreen" and give the error message.
     *
     * Available commands:
     *      -readMail
     *      -sendMail
     *      -shutdownMailServer
     *      -helpMailServerForCommands
     *
     * @param newString will parsed
     */
    void parseString(string newString);

    /**
     * Print all mail Archive
     *
     * -Read mailArchive file. Call the function
     * "writeGivenStringOnTheScreen" and print the all mail Archive.
     */
    void readMail();

    /**
     * Send Mail
     *
     * -Write mail into mailArchive file
     */
    void sendMail();

    /**
     * Check the MailServer directory
     *
     * -Check the MailServer directory which is called "MailServer".
     * "MailServer" directory is in the our source directory which is called "SourceFileGtuOS"
     * if the "MailServer" directory doesn't exist then create it.
     *
     */
    void checkMailServerDirectory();

    /**
     * Check the mailArchive file
     *
     * -Set mailArchiveFileName
     * -Check the mailArchive file..
     * mailArchive file is in the "MailServer" directory.
     * if the mailArchive file doesn't exist then create it.
     */
    void checkMailArchiveFile();

    /**
     * Print Given String On The Screen
     *
     * @param newString will written
     */
    void writeGivenStringOnTheScreen(string newString);

    /**
     * Shutdown MailServer
     *
     * -Set "isItClosed" variable false
     * -Handle other stuff
     */
    void shutdownMailServer();

    /**
     * Print All available commands On The Screen
     *
     * -Use "writeGivenStringOnTheScreen" function for print
     */
    void helpMailServerForCommands();



    /**
     * Get mailArchiveFileName
     */
    string getMailArchiveFileName() const{return mailArchiveFileName;}

    /**
     * Set mailArchiveFileName
     */
    void setMailArchiveFileName(string newMailArchiveFileName) {mailArchiveFileName = newMailArchiveFileName ;}


private:
    /**
     * Mail Archive File Name
     */
    string mailArchiveFileName;

};

#endif // MAILSERVER_H