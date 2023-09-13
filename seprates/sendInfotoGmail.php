<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $fname = $_POST["fname"];
    $lname = $_POST["lname"];
    $company = $_POST["company"];
    $email = $_POST["email"];
    $message = $_POST["comment"];
    
    // Compose and send an email
    $to = "ujoshua368@gmail.com";
    $subject = "New Contact Form Submission";
    $messageBody = "First Name: $fname\nLast Name: $lname\nCompany: $company\nEmail: $email\nMessage:\n$message";
    
    // Additional headers
    $headers = "From: $fname $lname <$email>\r\n";
    
    // Send the email
    if (mail($to, $subject, $messageBody, $headers)) {
        echo "Your message has been sent successfully.";
    } else {
        echo "Sorry, there was an error sending your message.";
    }
}
?>
