def SIGN_UP(type, login, password):
    return True
# True, если получилось зарегистрироваться (= не существует пользователя с таким же именем), False иначе

def SIGN_IN(login, password):
    return True
# Вызвать CHECK_PASSWORD на сервере

def IS_TUTOR(login):
    return True
# Проверка, что человек - Tutor

def GET_GROUPS(login):
    return 'Информатика\nМатематика\nКлоуны'
# Вернуть str с именами групп через '\n'

def ADD_GROUP(login, name):
    pass

def ENTER_GROUP(group_name):
    pass

def GET_STUDENTS_IN_GROUP(login, group_name):
    return 'Алиса\nБоб'

def GET_TASKS(login, group_name):
    return 'А\nВ\nС'

def ADD_TASK(login, group_name, task_name, student_name):
    pass

def ADD_STUDENT_IN_GROUP(login, group_name, student_name):
    pass

def GET_TASK_TEXT(login, group_name, task_name):
    return 'Решите в целых числах:\nx^n+y^n=z^n'

def GET_LAST_5_MESSAGES(login, group_name, task_name):
    return 'Q\nQQ\nQQQ\nQQQQ\nQqQQQQ'

def SEND_MESSAGE(login, group_name, task_name, message):
    pass