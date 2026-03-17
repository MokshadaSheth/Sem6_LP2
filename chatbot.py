import json
import random

# load dataset
with open("intents.json") as file:
    data = json.load(file)


def chatbot_response(user_input):

    user_input = user_input.lower()

    for intent in data["intents"]:
        for pattern in intent["patterns"]:

            if pattern in user_input:
                return random.choice(intent["responses"])
            if intent["tag"] in user_input:
                return random.choice(intent["responses"])

    return "Sorry, I don't understand. Please ask something about Ayurveda."


print("Ayurvedic Chatbot Started (type 'quit' to exit)\n")

# while True:

#     user_input = input("You: ")

#     if user_input.lower() == "quit":
#         break

#     response = chatbot_response(user_input)

#     print("Bot:", response)