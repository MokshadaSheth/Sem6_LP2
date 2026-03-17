from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel
from chatbot import chatbot_response

app = FastAPI()

class ChatRequest(BaseModel):
    message : str
    
    
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

@app.get("/")
def home():
    return {"message":"Ayurvedic Chatbot API running"}

@app.post("/chat")
def chat(request : ChatRequest):
    user_message = request.message
    response = chatbot_response(user_message)
    
    return{
        "user_message" : user_message,
        "bot_response" : response
    }