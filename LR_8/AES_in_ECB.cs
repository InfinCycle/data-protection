using System;
using System.Security.Cryptography;
using System.Text;
using System.IO;
// реалізацію AES в режимі шифрування ECB (Electronic Codebook)
class AESECBExample
{
    static void Main()
    {
        try
        {
            Aes aesObject = Aes.Create();
            aesObject.Mode = CipherMode.ECB; // Встановлюємо режим ECB

            // Встановлюємо ключ (32 байти для AES-256)
            aesObject.Key = new byte[32] { 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 
    0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10, 
    0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 
    0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10 };

            // Встановлюємо дані для шифрування
            string plaintext = "Hello, World!";
            byte[] plaintextBytes = Encoding.Default.GetBytes(plaintext);

            // Шифруємо дані
            byte[] encryptedData;
            using (MemoryStream msEncrypt = new MemoryStream())
            {
                using (ICryptoTransform encryptor = aesObject.CreateEncryptor())
                {
                    using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
                    {
                        csEncrypt.Write(plaintextBytes, 0, plaintextBytes.Length);
                        csEncrypt.FlushFinalBlock();
                    }
                }
                encryptedData = msEncrypt.ToArray();
            }

            // Виводимо зашифровані дані (мають виглядати як некоректні символи)
            Console.WriteLine("Зашифровані дані:\n");
            Console.WriteLine(Encoding.Default.GetString(encryptedData));

            // Розшифровуємо дані
            byte[] decryptedData;
            using (MemoryStream msDecrypt = new MemoryStream(encryptedData))
            {
                using (ICryptoTransform decryptor = aesObject.CreateDecryptor())
                {
                    using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
                    {
                        using (MemoryStream msPlainText = new MemoryStream())
                        {
                            csDecrypt.CopyTo(msPlainText);
                            decryptedData = msPlainText.ToArray();
                        }
                    }
                }
            }

            // Виводимо розшифровані дані (повинні збігатися з вихідним текстом)
            Console.WriteLine("\nРозшифровані дані:\n");
            Console.WriteLine(Encoding.Default.GetString(decryptedData));
        }
        catch (Exception e)
        {
            Console.WriteLine("Помилка: {0}", e.Message);
        }
    }
}