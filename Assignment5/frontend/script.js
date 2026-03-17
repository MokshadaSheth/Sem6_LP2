function toggleChat() {
  const chat = document.getElementById("chatContainer")
  chat.style.display = chat.style.display === "flex" ? "none" : "flex"
}

function openChat() {
  document.getElementById("chatContainer").style.display = "flex"
}

async function sendMessage() {

  const input = document.getElementById("userInput")
  const message = input.value

  if (!message) return

  const chatBox = document.getElementById("chatBox")

  // show user message
  chatBox.innerHTML += `<div class="user">You: ${message}</div>`

  input.value = ""

  const response = await fetch("http://localhost:8000/chat", {
    method: "POST",
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify({
      message: message
    })
  })

  const data = await response.json()

  // show bot response
  chatBox.innerHTML += `<div class="bot">Bot: ${data.bot_response}</div>`

  chatBox.scrollTop = chatBox.scrollHeight
}