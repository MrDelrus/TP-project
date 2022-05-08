import socket

symbol = '#'

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = '127.0.0.1'
port = 8080
s.connect((host, port))

def GET_ANSWER(request):
    l = len(request)
    request = f'{l:03}' + request
    s.send(request.encode("ascii", "ignore"))
    answer = s.recv(1024)
    to_return = answer.decode("ascii", "ignore")[1:]
    if to_return == 'True':
        return True
    if to_return == 'False':
        return False
    return to_return

def SIGN_UP(type, login, password):
    request = symbol + 'SIGN_UP' + symbol + type + symbol + login + symbol + password
    return GET_ANSWER(request)

def SIGN_IN(login, password):
    request = symbol + 'SIGN_IN' + symbol + login + symbol + password
    return GET_ANSWER(request)

def IS_TUTOR(login):
    request = symbol + 'IS_TUTOR' + symbol + login
    return GET_ANSWER(request)

def GET_GROUPS(login):
    request = symbol + 'GET_GROUPS' + symbol + login
    return GET_ANSWER(request)

def ADD_GROUP(login, name):
    request = symbol + 'ADD_GROUP' + symbol + login + symbol + name
    return GET_ANSWER(request)

def GET_STUDENTS_IN_GROUP(login, group_name):
    request = symbol + 'GET_STUDENT_IN_GROUP' + symbol + login + symbol + group_name
    return GET_ANSWER(request)

def GET_TASKS(login, group_name):
    request = symbol + 'GET_TASKS' + symbol + login + symbol + group_name
    return GET_ANSWER(request)

def ADD_TASK(login, group_name, task_name, student_name, problem):
    request = symbol + 'ADD_TASK' + symbol + login + symbol + group_name + symbol + task_name + symbol + student_name + symbol + problem
    return GET_ANSWER(request)

def ADD_STUDENT_IN_GROUP(login, group_name, student_name):
    request = symbol + 'ADD_STUDENT_IN_GROUP' + symbol + login + symbol + group_name + symbol + student_name
    return GET_ANSWER(request)

def GET_TASK_TEXT(login, group_name, task_name):
    request = symbol + 'GET_TASK_TEXT' + symbol + login + symbol + group_name + symbol + task_name
    return GET_ANSWER(request)

def GET_LAST_5_MESSAGES(login, group_name, task_name):
    request = symbol + 'GET_LAST_5_MESSAGES' + symbol + login + symbol + group_name + symbol + task_name
    return GET_ANSWER(request)

def SEND_MESSAGE(login, group_name, task_name, message):
    request = symbol + 'SEND_MESSAGE' + symbol + login + symbol + group_name + symbol + task_name + symbol + message
    return GET_ANSWER(request)
