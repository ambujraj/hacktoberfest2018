func validatePhoneNumber(value: String) -> Bool {
    let phoneRegex = "^\\d{3}-\\d{3}-\\d{4}$"
    let phoneTest = NSPredicate(format: "SELF MATCHES %@", phoneRegex)
    return phoneTest.evaluate(with: value)
}