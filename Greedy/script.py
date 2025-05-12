from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
import time

# Instagram credentials
USERNAME = "bet.my.way"
PASSWORD = "Satta@ipl4011"
MESSAGE = "Hello!" \
"   Fixed match winnner IPL 2025" \
"100% CONFIRM WINNERS " \
"JOIN AND RECOVER UR LOSSS " \
"100% WINNER "

# Set up WebDriver
options = webdriver.ChromeOptions()
options.add_argument("--headless")  # Run in the background (optional)
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)

def login():
    driver.get("https://www.instagram.com/accounts/login/")
    time.sleep(5)
    
    # Enter Username and Password
    username_input = driver.find_element(By.NAME, "username")
    password_input = driver.find_element(By.NAME, "password")
    
    username_input.send_keys(USERNAME)
    password_input.send_keys(PASSWORD)
    password_input.send_keys(Keys.RETURN)
    time.sleep(5)

def get_following():
    driver.get(f"https://www.instagram.com/{USERNAME}/following/")
    time.sleep(5)
    
    following_list = []
    users = driver.find_elements(By.XPATH, "//a[contains(@href, '/')]//span")
    for user in users:
        following_list.append(user.text)
    
    return following_list

def send_message(user):
    driver.get(f"https://www.instagram.com/direct/t/{user}/")
    time.sleep(5)
    
    message_box = driver.find_element(By.TAG_NAME, "textarea")
    message_box.send_keys(MESSAGE)
    message_box.send_keys(Keys.RETURN)
    time.sleep(2)

def main():
    login()
    following = get_following()
    print(f"Sending messages to {len(following)} users...")
    for user in following:
        send_message(user)
    driver.quit()
    print("All messages sent!")

if __name__ == "__main__":
    main()
