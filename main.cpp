#include <array>
#include <iostream>
#include <vector>

class Classifier {
  public:
    enum class Language {
      ENGLISH,
      DUTCH
    };

    Language classify(const std::string& word) const;

  private:
    std::vector<double> m_weights;
};

Classifier::Language Classifier::classify(const std::string& word) const {
  using LetterEncoding = std::array<int, 26>;
  auto word_encoding = std::array<LetterEncoding, 30>();
  for(auto i = std::size_t(0); i != word.size(); ++i) {
    auto letter_encoding = LetterEncoding();
    letter_encoding[word[i]] = 1;
    word_encoding[i] = letter_encoding;
  }
}

int main() {
  auto classifier = Classifier();
  classifier.classify("hello");
}
