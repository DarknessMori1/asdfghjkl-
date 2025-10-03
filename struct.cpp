#include <iostream>
#include <iomanip>  // Для функций setfill, setw
#include <string>   // Для функции string()
using namespace std;

// Структура CELL для работы с битовыми полями
// Имитирует структуру ячейки текста с атрибутами форматирования
struct CELL {   
    unsigned short character  : 8;  // 00000000 ????????
    unsigned short foreground : 3;  // 00000??? 00000000
    unsigned short intensity  : 1;  // 0000?000 00000000
    unsigned short background : 3;  // 0???0000 00000000
    unsigned short blink      : 1;  // ?0000000 00000000
} ;

int main(int argc, char* argv[]) {
    CELL my_cell;
    
    // Инициализация структуры значениями по умолчанию
    my_cell.character = 15;
    my_cell.foreground = 7;
    my_cell.background = 2;
    my_cell.blink = 1;
    my_cell.intensity = 0;

    cout << "=== Программа для работы со структурой CELL ===" << endl;
    cout << "Инициализация структуры:" << endl;
    cout << "character: " << my_cell.character << endl;
    cout << "foreground: " << my_cell.foreground << endl;
    cout << "background: " << my_cell.background << endl;
    cout << "intensity: " << my_cell.intensity << endl;
    cout << "blink: " << my_cell.blink << endl;
    cout << "Размер структуры в байтах: " << sizeof(my_cell) << endl;
    
    // Выводим hex значение исходной структуры в памяти
    cout << "\nHex значение структуры в памяти: 0x" 
         << hex << uppercase << setfill('0') << setw(4)
         << *reinterpret_cast<unsigned short*>(&my_cell) 
         << dec << endl << endl;

    unsigned short input_hex;
    bool all_ok = false;
    
    // Сохраняем исходные значения для сравнения
    unsigned short orig_character = my_cell.character;
    unsigned short orig_foreground = my_cell.foreground;
    unsigned short orig_background = my_cell.background;
    unsigned short orig_blink = my_cell.blink;
    unsigned short orig_intensity = my_cell.intensity;  // Сохраняем исходное значение intensity

    // Основной цикл программы
    while (!all_ok){
        cout << "\nИтерация ввода:" << endl;
        cout << "Введите hex значение для структуры CELL (или 0xFFFF для выхода): ";
        
        // Проверяем корректность ввода
        if (!(cin >> hex >> input_hex)) {
            cout << "Ошибка ввода! Попробуйте еще раз." << endl;
            cin.clear();  // Очищаем флаги ошибок
            cin.ignore(10000, '\n');  // Игнорируем неверный ввод
            continue;
        }
        cin >> dec;  // Возвращаем десятичный режим
        
        if (input_hex == 0xFFFF) {
            cout << "Выход из программы." << endl;
            break;
        }
        
        cout << "\nИсходные значения для сравнения:" << endl;
        cout << "character=15, foreground=7, background=2, blink=1, intensity=0" << endl;

        // Присваиваем hex значение структуре
        my_cell = *reinterpret_cast<CELL*>(&input_hex);
        
        cout << "\nПосле присвоения hex значения:" << endl;
        cout << "my_cell.character = " << my_cell.character << endl;
        cout << "my_cell.foreground = " << my_cell.foreground << endl;
        cout << "my_cell.background = " << my_cell.background << endl;
        cout << "my_cell.blink = " << my_cell.blink << endl;
        cout << "my_cell.intensity = " << my_cell.intensity << endl;
        
        // Выводим новое hex значение в памяти
        cout << "Новое hex значение структуры: 0x" 
             << hex << uppercase << setfill('0') << setw(4) 
             << *reinterpret_cast<unsigned short*>(&my_cell) 
             << dec << endl;

        // Используем сохраненное исходное значение intensity
        
        // Проверяем, изменился ли только intensity
        bool only_intensity_changed = 
            (my_cell.character == orig_character) &&
            (my_cell.foreground == orig_foreground) &&
            (my_cell.background == orig_background) &&
            (my_cell.blink == orig_blink) &&
            (my_cell.intensity != orig_intensity); // intensity действительно изменился

        if (only_intensity_changed) {
            cout << "\n✓ УСПЕХ! Изменилось только поле intensity!" << endl;
            all_ok = true;
        } else {
            cout << "\n✗ Проблема: изменились другие поля помимо intensity" << endl;
            cout << "Попробуйте другое значение." << endl;
        }
        cout << "\n" << string(50, '-') << endl;
    }
    
    return 0;
}