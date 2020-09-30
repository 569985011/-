from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time
Amount='1.11'

def logIn(driver):
    driver.get("https://e.gtfund.com/Etrade/TradeJijin/chongzhi/id/006597")
    try:
        driver.find_element_by_id('username').send_keys('350301199407010010')
        time.sleep(0.2)
        driver.find_element_by_id('password').send_keys('11739658')
        #人工填写验证码
        time.sleep(8)
        element=driver.find_element_by_class_name("gt-btn.gt-btn-primary.J_submit.btn-login.gt-radius.gt-btn-big")
        driver.execute_script("arguments[0].click();", element)
        
    except:
        print("LogIn()异常，或许是输完验证码就人工登录了，请查看脚本是否正常运行。")
        
        
def ReadInf(browser):
    #勾选阅读风险提示涵&点击下一步
    time.sleep(0.5)
    
    element=browser.find_element_by_xpath("//input[@type='checkbox']")
    browser.execute_script("arguments[0].click();", element)
    
    element=browser.find_element_by_xpath('/html/body/div[3]/div[2]/div/div/div[2]/div[7]/button[2]')
    browser.execute_script("arguments[0].click();", element)

    
def yanZhengMa(browser):
    #尚未完成
    
    pic=browser.find_element_by_class_name("J_vcode_img.vcode_img")
    return pytesseract.image_to_string(pic)

    
def fill(browser):
    #填写申购金额
    browser.find_element_by_class_name("J_applysum").send_keys(Amount)
    time.sleep(0.5)


def get(browser):
    #输入密码&点击确认
    browser.find_element_by_class_name('passwordInput').send_keys("11739658")
    time.sleep(0.5)
    element=browser.find_element_by_class_name('gt-btn.gt-btn-primary.gt-radius.J_submit.active')
    browser.execute_script("arguments[0].click();", element)

def goOn(browser):
    #返回申购首页
    browser.get("https://e.gtfund.com/Etrade/TradeJijin/chongzhi/id/006597")
    
def main():
    driver = webdriver.Chrome()
    logIn(driver)
    for i in range(2000):
        try:
            element = WebDriverWait(driver, 100).until(
            EC.presence_of_element_located((By.CLASS_NAME, "J_applysum"))
            )
        except:
            print("没有找到 J_applysum申购金额输入框")
            goOn(driver)
        finally:        
            fill(driver)
            
        try:
            element = WebDriverWait(driver, 100).until(
            EC.presence_of_element_located((By.CLASS_NAME, "risk-fit-cb"))
            )
        except:
            print("没有找到 risk-fid-cb风险提示涵勾选框")
            goOn(driver)
        finally:                    
            ReadInf(driver)
            
        try:
            element = WebDriverWait(driver, 100).until(
            EC.presence_of_element_located((By.CLASS_NAME, "passwordInput"))
            )
        except:
            print("没有找到 passwordInput密码输入框")
            goOn(driver)
        finally:                    
            get(driver)
        

        try:
            element = WebDriverWait(driver,100).until(
                EC.presence_of_element_located((By.CLASS_NAME, "gt-btn.gt-btn-primary.gt-radius"))
            )
        except:
            print("没有找到 ge-btn-primary.ge-radius申购结果页")
            goOn(driver)
        finally:
            goOn(driver)

main()

