let counter=10;
setInterval(() => {
    const now = new Date();

    counter--;
    // HH:MM:SS format
    const time24hr = now.toTimeString().split(' ')[0];
    console.log(time24hr);
    // HH:MM:SS AM/PM format
    const hours12hr = now.getHours() > 12 ? now.getHours() - 12 : now.getHours();
    const minutes = now.getMinutes().toString().padStart(2, '0');
    const seconds = now.getSeconds().toString().padStart(2, '0');
    const ampm = now.getHours() >= 12 ? 'PM' : 'AM';
    const time12hr = `${hours12hr}:${minutes}:${seconds} ${ampm}`;
    console.log(time12hr);

    if(counter==0){
        clearInterval();
    }
}, 1000);