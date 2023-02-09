#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		auto it = m_map.upper_bound(keyEnd);
		while(it!=m_map.find(keyBegin))
			--it;
		auto iter = m_map.upper_bound(keyEnd);
		//m_map.erase(iter);

    }

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};