import tkinter as tk
import scripts

class Interface:

    def __init__(self):
        self.run()

    def run(self):
        root = tk.Tk()
        root.title("<<Название проекта>>")
        root.geometry('1000x600+500+200')
        root.resizable(False, False)
        # root.configure(bg='yellow')
        self.project_name = tk.Label(text='<<Название проекта>>')
        self.project_name.place(relheight=0.08, relwidth=0.2, relx=0.1, rely=0.1)
        self.GET_MAIN()
        root.mainloop()

    def GET_MAIN(self):
        self.btn_sign_up = tk.Button(text='Sign up', command=self.MAIN_TO_SU)
        self.btn_sign_up.place(relheight=0.08, relwidth=0.2, relx = 0.40, rely = 0.3)
        self.btn_sign_in = tk.Button(text='Sign in', height=2, width=10, command=self.MAIN_TO_SI)
        self.btn_sign_in.place(relheight=0.08, relwidth=0.2, relx = 0.4, rely = 0.5)

    def DEL_MAIN(self):
        self.btn_sign_up.destroy()
        self.btn_sign_in.destroy()

    def GET_SU(self):
        self.label_type = tk.Label(text="Who are you, 'student' or 'tutor'?")
        self.label_type.place(relheight = 0.08, relwidth = 0.4, relx = 0.1, rely = 0.3)
        self.entry_type = tk.Entry(justify="center", width=20)
        self.entry_type.place(relheight=0.08, relwidth=0.2, relx = 0.50, rely = 0.3)

        self.label_name = tk.Label(text="Create name\n(from 4 to 12 symbols (but not '#'))")
        self.label_name.place(relheight=0.08, relwidth=0.4, relx=0.1, rely=0.5)
        self.entry_name = tk.Entry(justify="center", width=20)
        self.entry_name.place(relheight=0.08, relwidth=0.2, relx = 0.50, rely = 0.5)

        self.label_password = tk.Label(text="Create password\n(from 4 to 12 symbols (but not '#'))")
        self.label_password.place(relheight=0.08, relwidth=0.4, relx=0.1, rely=0.7)
        self.entry_password = tk.Entry(justify="center", width=20)
        self.entry_password.place(relheight=0.08, relwidth=0.2, relx = 0.50, rely = 0.7)

        self.create_account = tk.Button(text='Create account', command=lambda : self.SIGN_UP(self.entry_type.get(), self.entry_name.get(), self.entry_password.get()))
        self.create_account.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.85)

        self.go_back = tk.Button(text='Back', command=self.SU_TO_MAIN)
        self.go_back.place(relheight=0.08, relwidth=0.2, relx=0.05, rely=0.85)

    def DEL_SU(self):
        self.label_type.destroy()
        self.entry_type.destroy()
        self.label_name.destroy()
        self.entry_name.destroy()
        self.label_password.destroy()
        self.entry_password.destroy()
        self.create_account.destroy()
        self.go_back.destroy()
        self.go_back.destroy()
        self.DEL_WARNINGS_IN_SU()

    def DEL_WARNINGS_IN_SU(self):
        if hasattr(self, 'warning_type_in_SU') and self.warning_type_in_SU.winfo_exists():
            self.warning_type_in_SU.destroy()
        if hasattr(self, 'warning_long_name_in_SU') and self.warning_long_name_in_SU.winfo_exists():
            self.warning_long_name_in_SU.destroy()
        if hasattr(self, 'warning_short_name_in_SU') and self.warning_short_name_in_SU.winfo_exists():
            self.warning_short_name_in_SU.destroy()
        if hasattr(self, 'warning_long_password_in_SU') and self.warning_long_password_in_SU.winfo_exists():
            self.warning_long_password_in_SU.destroy()
        if hasattr(self, 'warning_short_password_in_SU') and self.warning_short_password_in_SU.winfo_exists():
            self.warning_short_password_in_SU.destroy()
        if hasattr(self, 'warning_old_name_in_SU') and self.warning_old_name_in_SU.winfo_exists():
            self.warning_old_name_in_SU.destroy()

    def SIGN_UP(self, type, login, password):
        self.DEL_WARNINGS_IN_SU()
        is_good = True
        if type != 'tutor' and type != 'student':
            self.warning_type_in_SU = tk.Label(text='Wrong type', fg='red')
            self.warning_type_in_SU.place(relheight=0.08, relwidth=0.2, relx = 0.75, rely = 0.3)
            is_good = False
        if len(login) < 4:
            self.warning_short_name_in_SU = tk.Label(text='Your name is\n too short', fg='red')
            self.warning_short_name_in_SU.place(relheight=0.08, relwidth=0.2, relx = 0.75, rely = 0.5)
            is_good = False
        if len(login) > 12:
            self.warning_long_name_in_SU = tk.Label(text='Your name is\n too long', fg='red')
            self.warning_long_name_in_SU.place(relheight=0.08, relwidth=0.2, relx=0.75, rely=0.5)
            is_good = False
        if len(password) < 4:
            self.warning_short_password_in_SU = tk.Label(text='Your password is\n too short', fg='red')
            self.warning_short_password_in_SU.place(relheight=0.08, relwidth=0.2, relx=0.75, rely=0.7)
            is_good = False
        if len(password) > 16:
            self.warning_long_password_in_SU = tk.Label(text='Your password is\n too long', fg='red')
            self.warning_long_password_in_SU.place(relheight=0.08, relwidth=0.2, relx=0.75, rely=0.7)
            is_good = False
        if is_good:
            if scripts.SIGN_UP(type, login, password):
                self.SU_TO_MAIN()
            else:
                self.warning_old_name_in_SU = tk.Label(text='This user is already exist', fg='red')
                self.warning_old_name_in_SU.place(relheight=0.08, relwidth=0.2, relx = 0.75, rely = 0.5)


    def GET_SI(self):
        self.label_name = tk.Label(text="Write your name")
        self.label_name.place(relheight=0.08, relwidth=0.4, relx=0.1, rely=0.4)
        self.entry_name = tk.Entry(justify="center", width=20)
        self.entry_name.place(relheight=0.08, relwidth=0.2, relx=0.50, rely=0.4)

        self.label_password = tk.Label(text="Write your\npassword")
        self.label_password.place(relheight=0.08, relwidth=0.4, relx=0.1, rely=0.6)
        self.entry_password = tk.Entry(justify="center", width=20)
        self.entry_password.place(relheight=0.08, relwidth=0.2, relx=0.50, rely=0.6)

        self.btn_enter_account = tk.Button(text='Enter', command=lambda : self.SIGN_IN(self.entry_name.get(), self.entry_password.get()))
        self.btn_enter_account.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.85)

        self.go_back = tk.Button(text='Back', command=self.SI_TO_MAIN)
        self.go_back.place(relheight=0.08, relwidth=0.2, relx=0.05, rely=0.85)

    def DEL_SI(self):
        self.label_name.destroy()
        self.entry_name.destroy()
        self.label_password.destroy()
        self.entry_password.destroy()
        self.btn_enter_account.destroy()
        self.go_back.destroy()
        if hasattr(self, 'warning_in_SI') and self.warning_in_SI.winfo_exists():
            self.warning_in_SI.destroy()

    def SIGN_IN(self, *args):
        is_okey = scripts.SIGN_IN(*args)
        if is_okey:
            self.SI_TO_PERSON(args[0])
        else:
            self.warning_in_SI = tk.Label(text='Wrong name or password', fg='red')
            self.warning_in_SI.place(relheight=0.08, relwidth=0.2, relx=0.4, rely=0.75)

    def GET_PERSON(self, login):
        self.is_tutor = scripts.IS_TUTOR(login)

        self.person_name = tk.Label(text=login, font=('Arial', 20), fg='white', bg='green')
        self.person_name.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.1)

        self.label_group_name = tk.Label(text='Name of group:')
        self.label_group_name.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.4)
        self.entry_group_name = tk.Entry(justify="center", width=20)
        self.entry_group_name.place(relheight=0.08, relwidth=0.2, relx = 0.70, rely = 0.55)

        self.GROUPS_RELOAD(login)

        self.btn_enter_group = tk.Button(text='Open', command=lambda : self.PERSON_TO_GROUP(login, self.entry_group_name.get()))
        self.btn_enter_group.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.85)

        self.go_back = tk.Button(text='Back', command=self.PERSON_TO_SI)
        self.go_back.place(relheight=0.08, relwidth=0.2, relx=0.05, rely=0.85)

        if self.is_tutor:
            self.add_group_button = tk.Button(text='Create', command=lambda : self.ADD_GROUP(login, self.entry_group_name.get()))
            self.add_group_button.place(relheight=0.08, relwidth=0.2, relx=0.38, rely=0.85)

    def DEL_PERSON(self):
        self.person_name.destroy()
        self.label_group_name.destroy()
        self.entry_group_name.destroy()
        self.list_of_groups.destroy()
        self.btn_enter_group.destroy()
        self.go_back.destroy()
        if self.is_tutor:
            self.add_group_button.destroy()
        if hasattr(self, 'warning_wrong_group_name') and self.warning_wrong_group_name.winfo_exists():
            self.warning_wrong_group_name.destroy()
        del self.groups
        del self.is_tutor

    def ADD_GROUP(self, login, group_name):
        if not group_name in self.groups:
            scripts.ADD_GROUP(login, group_name)
            self.GROUPS_RELOAD(login)

    def GROUPS_RELOAD(self, login):
        self.groups = scripts.GET_GROUPS(login).split('\n')
        if hasattr(self, 'list_of_groups') and self.list_of_groups.winfo_exists():
            self.list_of_groups.destroy()
        self.list_of_groups = tk.Label(text='Your groups:\n' + '\n'.join(self.groups), pady=0)
        self.list_of_groups.place(relheight=0.4, relwidth=0.4, relx=0.1, rely=0.3)

    def GET_GROUP(self, login, group_name):
        self.is_tutor = scripts.IS_TUTOR(login)

        self.person_name = tk.Label(text=login, font=('Arial', 20), fg='white', bg='green')
        self.person_name.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.1)

        self.group_name = tk.Label(text=group_name, font=('Arial', 20))
        self.group_name.place(relheight=0.08, relwidth=0.2, relx=0.4, rely=0.1)

        self.label_task_name = tk.Label(text='Choose task:')
        self.label_task_name.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.4)
        self.entry_task_name = tk.Entry(justify="center", width=20)
        self.entry_task_name.place(relheight=0.08, relwidth=0.2, relx=0.70, rely=0.55)

        self.TASKS_RELOAD(login, group_name)

        self.btn_enter_task = tk.Button(text='Open',
                                        command=lambda: self.GROUP_TO_TASK(login, group_name, self.entry_task_name.get()))
        self.btn_enter_task.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.85)

        self.go_back = tk.Button(text='Back', command=lambda: self.GROUP_TO_PERSON(login))
        self.go_back.place(relheight=0.08, relwidth=0.2, relx=0.05, rely=0.85)

        if self.is_tutor:
            self.add_task_button = tk.Button(text='Create',
                                             command=lambda: self.GROUP_TO_CREATE_TASK(login, group_name))
            self.add_task_button.place(relheight=0.08, relwidth=0.2, relx=0.38, rely=0.85)

            self.btn_add_student = tk.Button(text='Add student',
                                             command=lambda: self.GROUP_TO_ADD_STUDENT_TO_GROUP(login, group_name))
            self.btn_add_student.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.4)

    def DEL_GROUP(self):
        self.person_name.destroy()
        self.group_name.destroy()
        self.list_of_tasks.destroy()
        self.label_task_name.destroy()
        self.entry_task_name.destroy()
        self.btn_enter_task.destroy()
        self.go_back.destroy()
        if self.is_tutor:
            self.add_task_button.destroy()
            self.btn_add_student.destroy()
        if hasattr(self, 'warning_wrong_task_name') and self.warning_wrong_task_name.winfo_exists():
            self.warning_wrong_task_name.destroy()
        del self.tasks
        del self.is_tutor

    def ADD_TASK(self, login, group_name, task_name, student_name, problem):
        self.DEL_WARNINGS_IN_CREATE_TASK()
        self.is_good = True
        if task_name in self.tasks:
            self.is_good = False
            self.warning_wrong_new_task_name = tk.Label(text='This task is\n already exist', fg='red')
            self.warning_wrong_new_task_name.place(relheight=0.08, relwidth=0.2, relx=0.4, rely=0.3)
        if student_name not in self.students:
            self.is_good = False
            self.warning_wrong_student_name = tk.Label(text='This student are not\n in the group', fg='red')
            self.warning_wrong_student_name.place(relheight=0.08, relwidth=0.2, relx=0.40, rely=0.5)
            return
        if self.is_good:
            del self.is_good
            scripts.ADD_TASK(login, group_name, task_name, student_name, problem)
            self.CREATE_TASK_TO_GROUP(login, group_name)
        else:
            del self.is_good


    def TASKS_RELOAD(self, login, group_name):
        self.tasks = scripts.GET_TASKS(login, group_name).split('\n')
        if hasattr(self, 'list_of_tasks') and self.list_of_tasks.winfo_exists():
            self.list_of_tasks.destroy()
        self.list_of_tasks = tk.Label(text='Your tasks:\n' + '\n'.join(self.tasks), pady=0)
        self.list_of_tasks.place(relheight=0.4, relwidth=0.4, relx=0.1, rely=0.3)

    def GET_TASK(self, login, group_name, task_name):
        self.person_name = tk.Label(text=login, font=('Arial', 20), fg='white', bg='green')
        self.person_name.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.1)

        self.group_name = tk.Label(text=group_name, font=('Arial', 20))
        self.group_name.place(relheight=0.08, relwidth=0.2, relx=0.4, rely=0.1)

        self.task_name = tk.Label(text=task_name, font=('Font', 15))
        self.task_name.place(relheight=0.08, relwidth=0.2, relx=0.4, rely=0.2)

        self.task_text = scripts.GET_TASK_TEXT(login, group_name, task_name)

        self.label_task_text = tk.Label(text=self.task_text)
        self.label_task_text.place(relheight=0.08, relwidth=0.2, relx=0.4, rely=0.4)

        self.btn_enter_chat = tk.Button(text='Open the chat',
                                        command=lambda: self.TASK_TO_CHAT(login, group_name, task_name))
        self.btn_enter_chat.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.85)

        self.go_back = tk.Button(text='Back', command=lambda: self.TASK_TO_GROUP(login, group_name))
        self.go_back.place(relheight=0.08, relwidth=0.2, relx=0.05, rely=0.85)

    def DEL_TASK(self):
        self.person_name.destroy()
        self.group_name.destroy()
        self.task_name.destroy()
        self.label_task_text.destroy()
        self.btn_enter_chat.destroy()
        self.go_back.destroy()

    def GET_CREATE_TASK(self, login, group_name):
        self.tasks = scripts.GET_TASKS(login, group_name).split('\n')

        self.person_name = tk.Label(text=login, font=('Arial', 20), fg='white', bg='green')
        self.person_name.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.1)

        self.students = scripts.GET_STUDENTS_IN_GROUP(login, group_name).split('\n')

        self.list_of_students = tk.Label(text='Students:\n' + '\n'.join(self.students), pady=0)
        self.list_of_students.place(relheight=0.4, relwidth=0.4, relx=0.65, rely=0.1)

        self.label_enter_task_name = tk.Label(text='Name of task:', pady=0)
        self.label_enter_task_name.place(relheight=0.08, relwidth=0.2, relx=0.2, rely=0.2)

        self.entry_task_name = tk.Entry(justify="center", width=20)
        self.entry_task_name.place(relheight=0.08, relwidth=0.2, relx=0.40, rely=0.2)

        self.label_enter_student_name = tk.Label(text='Name of student:', pady=0)
        self.label_enter_student_name.place(relheight=0.08, relwidth=0.2, relx=0.2, rely=0.4)

        self.entry_student_name = tk.Entry(justify="center", width=20)
        self.entry_student_name.place(relheight=0.08, relwidth=0.2, relx=0.40, rely=0.4)

        self.label_enter_problem = tk.Label(text='Problem:', pady=0)
        self.label_enter_problem.place(relheight=0.08, relwidth=0.2, relx=0.45, rely=0.55)

        self.entry_problem = tk.Entry(justify="center", width=40)
        self.entry_problem.place(relheight=0.2, relwidth=0.6, relx=0.2, rely=0.6)

        self.btn_create = tk.Button(text='Create',
                                    command=lambda: self.ADD_TASK(login, group_name, self.entry_task_name.get(), self.entry_student_name.get(), self.entry_problem.get()))
        self.btn_create.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.85)

        self.go_back = tk.Button(text='Back', command=lambda: self.CREATE_TASK_TO_GROUP(login, group_name))
        self.go_back.place(relheight=0.08, relwidth=0.2, relx=0.05, rely=0.85)

    def DEL_CREATE_TASK(self):
        self.person_name.destroy()
        self.list_of_students.destroy()
        self.label_enter_task_name.destroy()
        self.entry_task_name.destroy()
        self.label_enter_student_name.destroy()
        self.entry_student_name.destroy()
        self.label_enter_problem.destroy()
        self.entry_problem.destroy()
        self.btn_create.destroy()
        self.go_back.destroy()
        self.DEL_WARNINGS_IN_CREATE_TASK()
        del self.tasks
        del self.students

    def DEL_WARNINGS_IN_CREATE_TASK(self):
        if hasattr(self, 'warning_wrong_student_name') and self.warning_wrong_student_name.winfo_exists():
            self.warning_wrong_student_name.destroy()
        if hasattr(self, 'warning_wrong_new_task_name') and self.warning_wrong_new_task_name.winfo_exists():
            self.warning_wrong_new_task_name.destroy()

    def GET_ADD_STUDENT_TO_GROUP(self, login, group_name):

        self.label_enter_student_name = tk.Label(text='Name of student:', pady=0)
        self.label_enter_student_name.place(relheight=0.08, relwidth=0.2, relx=0.2, rely=0.4)

        self.entry_student_name = tk.Entry(justify="center", width=20)
        self.entry_student_name.place(relheight=0.08, relwidth=0.2, relx=0.40, rely=0.4)

        self.btn_add_student = tk.Button(text='Add',
                                         command=lambda: scripts.ADD_STUDENT_IN_GROUP(login, group_name, self.entry_student_name.get()))
        self.btn_add_student.place(relheight=0.08, relwidth=0.2, relx=0.7, rely=0.85)

        self.go_back = tk.Button(text='Back', command=lambda: self.ADD_STUDENT_TO_GROUP_TO_GROUP(login, group_name))
        self.go_back.place(relheight=0.08, relwidth=0.2, relx=0.05, rely=0.85)


    def DEL_ADD_STUDENT_TO_GROUP(self):
        self.label_enter_student_name.destroy()
        self.entry_student_name.destroy()
        self.btn_add_student.destroy()
        self.go_back.destroy()

    def GET_CHAT(self, login, group_name, task_name):
        self.discussion = tk.Label(text=scripts.GET_LAST_5_MESSAGES(login, group_name, task_name), justify='left')
        self.discussion.place(relx=0.3, rely=0.3)

        self.entry_message = tk.Entry(justify="center", width=60)
        self.entry_message.place(relheight=0.08, relwidth=0.4, relx=0.3, rely=0.85)

        self.btn_send_message = tk.Button(text='Send', command=lambda: self.SEND_MESSAGE(login, group_name, task_name, self.entry_message.get()))
        self.btn_send_message.place(relheight=0.08, relwidth=0.2, relx=0.75, rely=0.85)

        self.go_back = tk.Button(text='Back', command=lambda: self.CHAT_TO_TASK(login, group_name, task_name))
        self.go_back.place(relheight=0.08, relwidth=0.2, relx=0.05, rely=0.85)

    def DEL_CHAT(self):
        self.discussion.destroy()
        self.entry_message.destroy()
        self.btn_send_message.destroy()
        self.go_back.destroy()

    def SEND_MESSAGE(self, login, group_name, task_name, message):
        scripts.SEND_MESSAGE(login, group_name, task_name, message)
        self.discussion.config(text=scripts.GET_LAST_5_MESSAGES(login, group_name, task_name))

    def MAIN_TO_SU(self):
        self.DEL_MAIN()
        self.GET_SU()

    def SU_TO_MAIN(self):
        self.DEL_SU()
        self.GET_MAIN()

    def MAIN_TO_SI(self):
        self.DEL_MAIN()
        self.GET_SI()

    def SI_TO_MAIN(self):
        self.DEL_SI()
        self.GET_MAIN()

    def SI_TO_PERSON(self, name):
        self.DEL_SI()
        self.GET_PERSON(name)

    def PERSON_TO_SI(self):
        self.DEL_PERSON()
        self.GET_SI()

    def PERSON_TO_GROUP(self, login, group_name):
        if group_name not in self.groups:
            self.warning_wrong_group_name = tk.Label(text='You have not\n this group', fg='red')
            self.warning_wrong_group_name.place(relheight=0.08, relwidth=0.2, relx=0.70, rely=0.7)
            return
        self.DEL_PERSON()
        self.GET_GROUP(login, group_name)

    def GROUP_TO_PERSON(self, login):
        self.DEL_GROUP()
        self.GET_PERSON(login)

    def GROUP_TO_TASK(self, login, group_name, task_name):
        if task_name not in self.tasks:
            self.warning_wrong_task_name = tk.Label(text='You have not\nthis task', fg='red')
            self.warning_wrong_task_name.place(relheight=0.08, relwidth=0.2, relx=0.70, rely=0.7)
            return
        self.DEL_GROUP()
        self.GET_TASK(login, group_name, task_name)

    def TASK_TO_GROUP(self, login, group_name):
        self.DEL_TASK()
        self.GET_GROUP(login, group_name)

    def GROUP_TO_CREATE_TASK(self, login, group_name):
        self.DEL_GROUP()
        self.GET_CREATE_TASK(login, group_name)

    def CREATE_TASK_TO_GROUP(self, login, group_name):
        self.DEL_CREATE_TASK()
        self.GET_GROUP(login, group_name)

    def TASK_TO_CHAT(self, login, group_name, task_name):
        self.DEL_TASK()
        self.GET_CHAT(login, group_name, task_name)

    def CHAT_TO_TASK(self, login, group_name, task_name):
        self.DEL_CHAT()
        self.GET_TASK(login, group_name, task_name)

    def GROUP_TO_ADD_STUDENT_TO_GROUP(self, login, group_name):
        self.DEL_GROUP()
        self.GET_ADD_STUDENT_TO_GROUP(login, group_name)

    def ADD_STUDENT_TO_GROUP_TO_GROUP(self, login, group_name):
        self.DEL_ADD_STUDENT_TO_GROUP()
        self.GET_GROUP(login, group_name)

main = Interface()
