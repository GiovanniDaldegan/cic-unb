from flask import Flask, render_template
from flask_socketio import SocketIO, emit, send

app = Flask(__name__)
app.config["SECRET_KEY"] = "secret!"
socketio = SocketIO(app)

class Message:
    def __init__(self, author:str, content, timeStamp:int=0):
        self.author :str = author
        self.content = content
        self.timeStamp :int = timeStamp

    def formatMessage(self):
        return {
            "author" : self.author,
            "content" : self.content,
            "timeStamp" : self.timeStamp
        }

    def getAuthor(self) -> str:
        return self.author

    def getContent(self):
        return self.content

    def getTimeStamp(self):
        return self.timeStamp


class Client:
    def __init__(self, name:str):
        self.id :str = "12345"
        self.name :str = name
        self.room_id : str = ""
    
    def enterRoom(self, room_id:str):
        if getChatRoom(room_id):
            self.room_id = room_id

    def leaveRoom(self):
        self.room_id = ""

    def getRoomId(self) -> str:
        return self.room_id

class ChatRoom:
    def __init__(self, name:str, owner:Client):
        self.id = "id0"
        self.name :str = name
        self.owner :str = owner.name
        self.clients :list[str] = []
        self.messages :list[Message] = []

    def addClient(self, client:Client):
        self.clients.append(client.id)
        client.enterRoom(self.id)

    def removeClient(self, client_id:str):
        client_index = -1
        for client_index in range(len(self.clients)):
            if self.clients[client_index] == client_id:
                break
        self.clients.pop(client_index)

    def addMessage(self, message:Message):
        self.messages.append(message)


chatrooms :dict[str, ChatRoom] = {}
clients :dict[str, Client] = {}


def verifyClientName(client_name:str) -> bool:
    for client in clients.values():
        if client.name == client_name:
            return True

    return False

def getClient(client_id:str) -> Client | None:
    if client_id in clients.keys():
        return clients[client_id]
    else:
        return None


def verifyRoomName(room_name:str) -> bool:
    for room in chatrooms.values():
        if room.name == room_name:
            return True

    return False

def getChatRoom(room_id:str) -> ChatRoom | None:
    if room_id in chatrooms:
        return chatrooms[room_id]
    else:
        return None

def listRooms() -> list[tuple[str, list[str]]]:
    return [(room.name, room.clients) for room in chatrooms.values()]

def getRoomMessages(room_id) -> list:
    messages = []
    if room_id in chatrooms:
        room = getChatRoom(room_id)
        if room:
            for message in room.messages:
                messages.append([message.author, message.content, message.timeStamp])
    return messages

def getRoomData(room_id:str) -> dict | None:
    room = getChatRoom(room_id)
    if room:
        return {
            "name" : room.name,
            "owner" : room.owner,
            "clients" : room.clients,
            "messages" : getRoomMessages(room_id)
        }
    else:
        return None

def emitGetRooms():
    emit("get_rooms", listRooms())


@app.route("/")
def index():
    return render_template("index.html")

#@app.route("/salas")
#def 

#@app.route("/salas/<room>") ??
#def 

@socketio.on("register")
def register_client(data):
    if verifyClientName(data["client_name"]):
        emit("user_already_exists")
        return

    newClient = Client(data["client_name"])
    clients[newClient.id] = newClient

    emitGetRooms() # TODO: checar se manda apenas para o cliente específico
    print(f"\"{newClient.name}\" foi registrado!")


@socketio.on("create_room")
def createRoom(data):
    if verifyRoomName(data["room_name"]):
        emit("room_already_exists")
        return

    client = getClient("12345")
    if client:
        newRoom = ChatRoom(data["room_name"], client)
        chatrooms[newRoom.id] = newRoom

        emitGetRooms()
        print(f"Sala \"{newRoom.name}\" criada!")


@socketio.on("enter_room")
def load_room(data):
    # TODO: determinar o id do client pela sua conexão, o socketio deve fornecer algo assim
    room = getChatRoom(data["room_id"])
    client = getClient("12345")

    if not room:
        emit("invalid_room")
    elif not client:
        emit("invalid_user")
    else:
        if client.getRoomId() != "":
            emit("user_already_in_room")
            return

        room.addClient(client)
        client.enterRoom(data["room_id"])

        emit("load_room", getRoomData(room.id))
        print(f"\"{client.name}\" entrou na sala \"{room.name}\"")


@socketio.on("leave_room")
def leaveRoom():
    client = getClient("12345")
    if not client:
        emit("invalid_user")
    else:
        room = getChatRoom(client.getRoomId())
        if not room:
            emit("invalid_room")
        else:
            room.removeClient(client.id)

            emitGetRooms()
            print(f"\"{client.name}\" saiu da sala \"{room.name}\"")
            client.leaveRoom() # client.leaveRoom()


@socketio.on("delete_room")
def deleteRoom(data):
    client = getClient("12345")
    if not client:
        emit("invalid_user")
    else:
        room = getChatRoom(data["room_id"])
        if not room:
            emit("invalid_room")
        else:
            if len(room.clients) != 0:
                emit("room_not_empty")
            else:
                del chatrooms[room.id]

                emitGetRooms()
                print(f"Sala \"{room.name}\" deletada")


@socketio.on("send_message")
def onClientMessage(data):
    # TODO: 
    client = getClient("12345")
    if client:
        room = getChatRoom(client.getRoomId())
        if room:
            msg = Message(client.name, data["content"])
            # room.addMessage(msg)
            
            chatrooms[room.id].messages.append(msg)

            # TODO: send to all clients in chatroom
            emit("get_message", msg.formatMessage(), broadcast=True)
            print(f"\"{client.name}\" mandou mensagem em {room.name}")


if __name__ == "__main__":
    socketio.run(app, debug=True) # type: ignore
