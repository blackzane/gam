#include <iostream>

// Prototypes des fonctions
size_t LongueurChaine(const char* chaine);
void CopierChaine(char* destination, const char* source);
void ConcatenerChaines(char* destination, const char* source);
char* TrouverCaractere(const char* chaine, char caractere);
size_t CompterOccurrences(const char* chaine, char caractere);
void CopierMemoire(void* destination, const void* source, size_t taille);
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille);
void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur);
size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats);
int ComparerChaines(const char* chaine1, const char* chaine2);
void ConvertirMinuscules(char* chaine);
bool EstChaineNumerique(const char* chaine);

int main() {
    std::cout << "=== TEST DES FONCTIONS DE MANIPULATION DE CHAINES STYLE C ===" << std::endl;
    std::cout << "Compilé avec C++ et CLang++" << std::endl << std::endl;
    
    // Test 1: Longueur de chaîne
    char message[] = "Bonjour le monde";
    std::cout << "1. Longueur de '" << message << "': " << LongueurChaine(message) << std::endl;
    
    // Test 2: Copie de chaîne
    char copie[50];
    CopierChaine(copie, message);
    std::cout << "2. Copie: '" << copie << "'" << std::endl;
    
    // Test 3: Concaténation
    char salutation[100] = "Hello ";
    ConcatenerChaines(salutation, "World!");
    std::cout << "3. Concaténation: '" << salutation << "'" << std::endl;
    
    // Test 4: Recherche de caractère
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        std::cout << "4. Caractère 'j' trouvé à la position: " << (position - message) << std::endl;
    } else {
        std::cout << "4. Caractère 'j' non trouvé" << std::endl;
    }
    
    // Test 5: Comptage d'occurrences
    std::cout << "5. Occurrences de 'o' dans '" << message << "': " 
              << CompterOccurrences(message, 'o') << std::endl;
    
    // Test 6: Extraction de sous-chaîne
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    std::cout << "6. Sous-chaîne (pos 3, longueur 5): '" << sous_chaine << "'" << std::endl;
    
    // Test 7: Division de chaîne
    char phrase[] = "pomme,orange,banane,kiwi";
    char fruits[10][100];
    size_t nb_fruits = DiviserChaine(phrase, ',', fruits, 10);
    
    std::cout << "7. Division de '" << phrase << "':" << std::endl;
    for (size_t i = 0; i < nb_fruits; i++) {
        std::cout << "   [" << i << "] " << fruits[i] << std::endl;
    }
    
    // Test 8: Fonctions mémoire
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    std::cout << "8. Copie mémoire (5 octets): '" << zone2 << "'" << std::endl;
    
    char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    std::cout << "9. Initialisation mémoire: '" << zone3 << "'" << std::endl;
    
    // Test 10: Comparaison de chaînes
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    std::cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " 
              << resultat_comparaison << std::endl;
    
    // Test 11: Conversion minuscules
    char mixte[] = "Hello World!";
    std::cout << "11. Avant conversion: '" << mixte << "'" << std::endl;
    ConvertirMinuscules(mixte);
    std::cout << "    Après conversion: '" << mixte << "'" << std::endl;
    
    // Test 12: Vérification numérique
    char numerique[] = "12345";
    char non_numerique[] = "12a45";
    std::cout << "12. '" << numerique << "' est numérique: " 
              << (EstChaineNumerique(numerique) ? "OUI" : "NON") << std::endl;
    std::cout << "    '" << non_numerique << "' est numérique: " 
              << (EstChaineNumerique(non_numerique) ? "OUI" : "NON") << std::endl;
    
    return 0;
}
size_t LongueurChaine(const char* chaine) {

    const char* Debut=chaine;
    while(*chaine != '\0'){
             chaine++;
    } 
    return chaine-Debut;

}
void CopierChaine(char* destination, const char* source) {
    while(*source !='/0'){
        *destination=*source;
        destination++;
        source++;
    }
    *destination='\0';
}
void ConcatenerChaines(char* destination, const char* source) {
    while(*source !='\0'){
        destination++;
    }
    while(*source !='\0'){
        *destination=*source;
        source++;
    }
    *destination ='\0';
}
char* TrouverCaractere(const char* chaine, char caractere) {
   while(*chaine !='\0'){
    if(*chaine==caractere){
        return (char*)chaine;
    }
    chaine++;
   }
    return nullptr;
}
size_t CompterOccurrences(const char* chaine, char caractere) {
  size_t compteur=0;
  while(*chaine !='\0'){
    if(*chaine==caractere){
        compteur++;
    }
    chaine++;
  }
    return 0;
}
void CopierMemoire(void* destination, const void* source, size_t taille) {
    unsigned char* d=(unsigned char*)destination;
    const unsigned char* s=(const unsigned char*)source;
    for(size_t i=0;i<taille;i++){
        *d=*s;
         d++;
        s++;
    }
}
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille) {
   unsigned char*zn=(unsigned char*)zone;
   for(size_t i=0;i<taille;i++){
    *zn=valeur;
    zn++;
   }
}
void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur) {
  source+=debut;
  for(size_t i=0;i<longueur;i++){
    if(*source=='\0'){
        break;
    }
    *destination=*source;
    destination++;
    source++;
   }
   *destination='\0';
}
size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats) {
   size_t compteur=0;
   size_t index_courant=0;
   while(*chaine !='\0' && compteur<max_resultats){
    if(*chaine==separateur){
        if(index_courant>0){
            resultat[compteur][index_courant]='\0';
            compteur++;
            index_courant=0;

        }
    }else{
        resultat[compteur][index_courant]=*chaine;
        index_courant++;
    }
    chaine++;
   }
   if(index_courant>0){
    resultat[compteur][index_courant]='\0';
    compteur++;
   }
    return 0;
}
int ComparerChaines(const char* chaine1, const char* chaine2) {
    while(*chaine1!='\0' && *chaine2!='\0'){
        if(*chaine1 !=*chaine2){
            chaine1++;
            chaine2++;
        }
        if(*chaine1=='\0' && *chaine2=='\0'){
            return 0;
        }else if(*chaine1=='\0'){
            return -1;
        }else{
            return 1;
        }
    }
    return 0;
}
void ConvertirMinuscules(char* chaine) {
  while(*chaine !='\0'){
    if(*chaine>='A' && *chaine<='Z'){
        *chaine+=32;
    }
  }
}
bool EstChaineNumerique(const char* chaine) {
    if(*chaine =='-'){
        chaine++;
    }
    while(*chaine!='\0'){
        if(*chaine<'0' || *chaine >'9'){
            return false;
        }
         chaine++;
    }
    return true;
}