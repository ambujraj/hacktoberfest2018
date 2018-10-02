export default function validatePhoneNumber(phone_number = null){
    let regex = /^\d(?:-\d{3}){3}\d$/
    return regex.test(phone_number); //exemple: 2-123-123-1231 returns true
}