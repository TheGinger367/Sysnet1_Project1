/* don't test program with more than this many tokens for input */
#define MAXARGS 32
/* class to hold input data */
/* feel free to add missing constructor, destructor, and getter/setter functions */
class Param {
    private:
        char *inputRedirect; /* file name or NULL */
        char *outputRedirect; /* file name or NULL */
        int background; /* either 0 (false) or 1 (true) */
        int argumentCount; /* number of tokens in argument vector */
        char *argumentVector[MAXARGS]; /* array of strings */
    puplic:
        void getUserInput();
        void printParams();

        char getInputRedirect();
        void setInputRedirect();

        char getOutputRedirect();
        void setOutputRedirect();

        int getBackground();
        void setBackground();

        int getArgumentCount();
        void setArgumentCount();
};