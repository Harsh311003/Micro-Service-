from django.core.mail import send_mail
from django.conf import settings

def smtp():
    try:
        print("Attempting to send email")
        subject="Request for update job status"
        message="Hello I am harsh kindly request you to please update job status according to given value"
        send_mail(
            subject,
            message,
            settings.EMAIL_HOST_USER,
            ["harshsharma311003@gmail.com"],
            fail_silently=False,
        )
        print("mail sent successfully")
    except Exception as err:
        print(f"showing error as {err}")


