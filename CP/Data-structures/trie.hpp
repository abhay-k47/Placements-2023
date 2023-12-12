/**
 * @file trie.hpp
 * @author abhay kumar keshari (akabhay9685@gmail.com)
 * @brief Implementation of Trie (Prefix tree): a tree data structure used to efficiently store and retrieve keys in a
 * dataset of strings
 * @version 0.1
 * @date 2023-08-03
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Trie
{
public:
  /**
   * @brief Construct a new Trie
   *
   * @param alphabet_size
   * @param first_alphabet
   */
  explicit Trie(size_t alphabet_size = 26, char first_alphabet = 'a')
      : root(nullptr)
      , ALPHABET_SIZE(alphabet_size)
      , FIRST_ALPHABET(first_alphabet)
  {
  }

  /**
   * @brief Insert a string into the trie
   *
   * @param str
   */
  void insert(const string& str)
  {
    if (root == nullptr)
      root = new Node(ALPHABET_SIZE);
    Node* curr = root;
    for (char c : str)
    {
      size_t index = c - FIRST_ALPHABET;
      if (curr->children[index] == nullptr)
      {
        curr->children[index] = new Node(ALPHABET_SIZE);
      }
      curr = curr->children[index];
    }
    curr->wordCount++;
  }

  /**
   * @brief Search a string in the trie
   *
   * @param str
   * @return true
   * @return false
   */
  bool search(const string& str) const
  {
    if (root == nullptr)
      return false;
    Node* curr = root;
    for (char c : str)
    {
      size_t index = c - FIRST_ALPHABET;
      if (curr->children[index] == nullptr)
      {
        return false;
      }
      curr = curr->children[index];
    }
    return curr->wordCount > 0;
  }

  /**
   * @brief Search a prefix in the trie
   *
   * @param str
   * @return true
   * @return false
   */
  bool prefix_search(const string& str) const
  {
    if (root == nullptr)
      return false;
    Node* curr = root;
    for (char c : str)
    {
      size_t index = c - FIRST_ALPHABET;
      if (curr->children[index] == nullptr)
      {
        return false;
      }
      curr = curr->children[index];
    }
    return true;
  }

  /**
   * @brief Erase a string from the trie
   *
   * @param str
   * @return true
   * @return false
   */
  bool erase(const string& str)
  {
    if (root == nullptr)
      return false;
    Node* curr = root;
    for (char c : str)
    {
      size_t index = c - FIRST_ALPHABET;
      if (curr->children[index] == nullptr)
      {
        return false;
      }
      curr = curr->children[index];
    }
  }

private:
  struct Node
  {
    vector<Node*> children;
    int wordCount;
    /**
     * @brief Construct a new Node
     *
     * @param alphabet_size
     */
    explicit Node(size_t alphabet_size)
        : children(vector<Node*>(alphabet_size, nullptr))
        , wordCount(0)
    {
    }
  };

  Node* root;
  const size_t ALPHABET_SIZE;
  const char FIRST_ALPHABET;
};

#endif
