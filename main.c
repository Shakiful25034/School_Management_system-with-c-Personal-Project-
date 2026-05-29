#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

// ==================================   Create New DataBase In NEW YEAR(2nd Function)  ================================================= //
int create_New_Data_Base(void)
{
    int n;
    printf("\nWhat do You want to Create?\n");
    printf("\t(i) Folder of classes and File's For classes. (Press 1)\n");
    printf("\t(ii) To go To next Step (Press 2)\n");
    printf("\t(iii) To Stop the process (Press 3 or anything else except 1 and 2)\n");

    printf("Enter = ");
    scanf("%d", &n);
    printf("\n");

    //Creating a year with year name and make sub-folder for all the classes of the school
    if (n==1)
    {
        int year;  //to create a main folder to store all the data of students of the year
        int Batch_number=1;
        printf("\nEnter the year: ");
        scanf("%d", &year);
        printf("\n");

        char main_folder_with_year[100];
        sprintf(main_folder_with_year, "mkdir \"%d\"", year); //Creating main folder using the name of the year
        system(main_folder_with_year);  //command for creating folder
        printf("\n\t\t ------------ Congratulations! New DataBase of the school for year %d is successfully created. ----------\t\t\n", year);



        char Folder_name_for_classes[200]; //variable name to store the name of the folder. like- Database of class 1,  Database of class 2 ........
        char create_Folder[200];

        int class_test;
        char class_test_before_mid[200];
        char class_test_name[200]; // for storing class test 1, class test 2, class test 3 .......
        char mid[200];
        char class_test_after_mid[200];
        char final_exam[200];


        
        //making Database-Folders for class 1 to 10 and mamke sub folders
        for (int i = 1; i <= 10; i++, Batch_number++)
        {
            //"sprintf" will add class and batch name in my string called "Folder- name"
            //sprintf(variable_name, "string contain", values that will be add)
            //We use "mkdir" as we are going to create a file using the string name
            sprintf(Folder_name_for_classes, "%d/Data-Base of class %d of Batch %d",year, i, Batch_number); //storing the full_name in Temp_folder_or_files_names
            sprintf(create_Folder, "mkdir \"%s\"", Folder_name_for_classes);
            system(create_Folder); //"System" keyword will help me to create folder.
            


            /*Creating all the sub-folders for the classes*/
            //Creating Files for Class-test-Before Mid_Term Exam
            printf("\nHow many class test you want to take for class %d before mid term exam?\n", i);
            printf("Enter: ");
            scanf("%d", &class_test);

            //Creating Folder for Class Test Before Mid Term Exam 
            sprintf(class_test_before_mid, "%s/Class Test Before Mid Term Exam", Folder_name_for_classes);
            sprintf(create_Folder, "mkdir \"%s\"", class_test_before_mid);
            system(create_Folder);

            //CT 1, 2, 3, 4, 5, 6 .............
            for (int j = 1; j <= class_test; j++)
            {
                sprintf(class_test_name, "%s/Class Test %d", class_test_before_mid, j);
                sprintf(create_Folder, "mkdir \"%s\"", class_test_name);
                system(create_Folder);
            }
            printf("\n\n\t -------You successfully Created %d files to store all the Data of the students of %d to store Class test makes Before mid----------------\t\n\n", class_test, i);


            /*Creating a Folder To store the Data Of Mid Term Exam*/
            char mid_term[100];
            sprintf(mid_term, "%s/Mid Term Exam", Folder_name_for_classes);
            sprintf(create_Folder, "mkdir \"%s\" ", mid_term);
            system(create_Folder);
            printf("\t\t-------     A File to store Mid Term Exam Data is Successfully created -------------------\t\t\n\n");



            /*Creating all the sub-folders for the classes*/
            //Creating Files for Class-test-After Mid_Term Exam
            printf("\nHow many class test you want to take for class %d After mid term exam?\n", i);
            printf("Enter: ");
            scanf("%d", &class_test);

            //Creating Folder for Class Test Before Mid Term Exam 
            sprintf(class_test_after_mid, "%s/Class Test After Mid Term Exam", Folder_name_for_classes);
            sprintf(create_Folder, "mkdir \"%s\"", class_test_after_mid);
            system(create_Folder);

            //CT 1, 2, 3, 4, 5, 6 .............
            for (int j = 1; j <= class_test; j++)
            {
                sprintf(class_test_name, "%s/Class Test %d" , class_test_after_mid, j);
                sprintf(create_Folder, "mkdir \"%s\" ", class_test_name);
                system(create_Folder);
            }
             printf("\n\t\t\t--------You successfully Created %d files to store all the Data of the students of %d to store Class test makes After mid------\t\t\t\n", class_test, i);




            /*
                if the student is in class 8 or higher then scholl can take some extra Caricular
                activities like - "Presentation", "Project Work", etc etc
            */

            if (i>=8 && i<=10)
            {
                int n;
                do
                {
                    printf("If you want to make a folder to store any data of marks like presentation or anything else then type '1'\n");
                    printf("if you don't want to amke any extra folder then press 'Zero(0)'\n");
                    printf("Enter: ");
                    scanf(" %d", &n);    
                    /* note:
                        scanf("%d")  →  \n buffer এ থেকে যায়  →  fgets() নষ্ট হয়
                        scanf(" %d") →  \n আগেই সরে যায়      →  fgets() ঠিকমতো কাজ করে
                    */

                    if ( n==1 )
                    {
                        char special_folder[100]; //To take input of the file. like- "presentation", "assignment" etc...
                        printf("Enter The file name: "); 
                        fgets(special_folder, sizeof(special_folder), stdin); //Taking input of special file name

                        char special_folder_without_new_line[100];
                        char character;

                        int i=0, j=0;
                        while (special_folder[i] != '\n')
                        {
                            special_folder_without_new_line[j] = special_folder[i];
                            i++;
                            j++;
                        }
                        special_folder_without_new_line[j] = '\0';
                        
                        sprintf(create_Folder , "mkdir \"%s\" ", special_folder_without_new_line); 
                        system(create_Folder);

                    }

                } while (n!=0);

            }


            printf("\n\n \t\t ==============////////--------    %s Folder is successfully created    -------- //////// ===========\t\t\n\n", Folder_name_for_classes);
        }

        printf("\n\n");
        printf("\t\t\t\t==========  Congratulations You successfully Created all the New folder for the students of Batch = %d  =========\t\t\t\t\n\n", Batch_number);
        printf("\n\n");
    }else if (n==2)
    {
        return 1;
    }else
    {
        printf("Invalid Input.😒😒");
        return 0;
    }


}




// ==================================   Main Student Function(1st Function)  ================================================= //
int students(void)
{
    int n;


    printf("What you Want to do?\n");

    printf("\t(i) Create a New Data-Base(press 1 from keyboard) \n"
        "\t(ii) Work with Old Database? (press 2 from keyboard)\n\n");

    printf("Input = ");
    scanf("%d", &n);
    printf("\n");


    if (n==1)
    {
        create_New_Data_Base();
    }else if (n==2)     //OLD DATABASE OF STUDENTS
    {
        printf("\t\t ===========   OLD STUDENT DATABASE    ============== \t\t\n");

        printf("\t(i) Read Data of students. input 1;\n"); //To know the info about students and to know marks tec etc..
        printf("\t(ii) Append means add New Data of Students. input 2;\n"); //To add new students Details or exam marks etc etc..
        printf("\t(iii) Change Data of Students. input 3;\n"); //If we Do some typing mistake in marks or students info

        printf("Input = ");
        scanf("%d", &n);
        printf("\n");


        //To access Data students
        if (n == 1)
        {
            /* //To know the info about students and to know marks tec etc.. */        //F
        }else if (n == 2)
        {
            /* //To add new students Details or exam marks etc etc.. */             //F
        }else if (n == 3)
        {
            /* //To add new students Details or exam marks etc etc.. */                 //F
        }else
        {
            printf("Invalid Input.😒😒");
            return 0;
        }










    }else
    {
        printf("Invalid Input.😒😒");
        return 0;
    }

    return 1;

}



int main()
{
    printf("\n \t\t\t \"Welcome to \'FAILURES ACADEMY\' \" \t\t\t \n\n\n");

    //selecting the sector
    printf("With whom you want to work with?\n");
    printf("Press 1 for Students and Press 2 for Teachers form your keyboard.\n");

    int n;
    printf("Input - ");
    scanf("%d", &n);

    if (n==1 || n==2)
    {
        if (n==1)
        {
            students();
        }else
        {
            //Teachers
        }


    }else
    {
        printf("Invalid Input.😒😒");
        return 0;
    }



    return 0;
}
