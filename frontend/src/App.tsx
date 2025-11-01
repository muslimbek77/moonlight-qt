import { useState, useEffect } from 'react'

interface User {
  id: number
  email: string
  name: string
  balance: string
}

interface Slot {
  id: number
  name: string
  ipAddress: string
  pinCode?: string
  status: string
}

function App() {
  const [isLogin, setIsLogin] = useState(true)
  const [user, setUser] = useState<User | null>(null)
  const [token, setToken] = useState<string | null>(localStorage.getItem('token'))
  const [loading, setLoading] = useState(false)
  const [error, setError] = useState('')
  const [success, setSuccess] = useState('')
  const [slot, setSlot] = useState<Slot | null>(null)
  
  const [formData, setFormData] = useState({
    email: '',
    password: '',
    name: '',
    cloudplayUsername: '',
    cloudplayPassword: '',
  })

  useEffect(() => {
    if (token) {
      fetchUserProfile()
    }
  }, [token])

  const fetchUserProfile = async () => {
    try {
      const response = await fetch('/api/auth/profile', {
        headers: {
          'Authorization': `Bearer ${token}`,
        },
      })
      if (response.ok) {
        const data = await response.json()
        setUser(data.user)
      } else {
        localStorage.removeItem('token')
        setToken(null)
      }
    } catch (err) {
      console.error('Profile fetch error:', err)
    }
  }

  const handleLogin = async (e: React.FormEvent) => {
    e.preventDefault()
    setLoading(true)
    setError('')

    try {
      const response = await fetch('/api/auth/login', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          email: formData.email,
          password: formData.password,
        }),
      })

      const data = await response.json()

      if (response.ok) {
        localStorage.setItem('token', data.token)
        setToken(data.token)
        setUser(data.user)
        setFormData({ ...formData, email: '', password: '' })
      } else {
        setError(data.error || 'Kirish xato')
      }
    } catch (err) {
      setError('Server bilan bog\'lanishda xatolik')
    } finally {
      setLoading(false)
    }
  }

  const handleRegister = async (e: React.FormEvent) => {
    e.preventDefault()
    setLoading(true)
    setError('')

    try {
      const response = await fetch('/api/auth/register', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          email: formData.email,
          password: formData.password,
          name: formData.name,
        }),
      })

      const data = await response.json()

      if (response.ok) {
        localStorage.setItem('token', data.token)
        setToken(data.token)
        setUser(data.user)
        setFormData({ ...formData, email: '', password: '', name: '' })
      } else {
        setError(data.error || 'Ro\'yxatdan o\'tishda xatolik')
      }
    } catch (err) {
      setError('Server bilan bog\'lanishda xatolik')
    } finally {
      setLoading(false)
    }
  }

  const handleEnableMoonlight = async () => {
    setLoading(true)
    setError('')
    setSuccess('')

    try {
      const response = await fetch('/api/slots/enable-moonlight', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
          'Authorization': `Bearer ${token}`,
        },
        body: JSON.stringify({
          username: formData.cloudplayUsername,
          password: formData.cloudplayPassword,
        }),
      })

      const data = await response.json()

      if (response.ok) {
        setSlot(data.slot)
        setSuccess(data.message || 'Moonlight muvaffaqiyatli yoqildi!')
      } else {
        setError(data.error || 'Moonlight yoqishda xatolik')
      }
    } catch (err) {
      setError('Server bilan bog\'lanishda xatolik')
    } finally {
      setLoading(false)
    }
  }

  const handleLogout = () => {
    localStorage.removeItem('token')
    setToken(null)
    setUser(null)
    setSlot(null)
  }

  if (user) {
    return (
      <div className="min-h-screen bg-gradient-to-br from-blue-900 via-purple-900 to-indigo-900">
        <div className="container mx-auto px-4 py-8">
          <header className="text-center mb-8">
            <h1 className="text-5xl font-bold text-white mb-2">CloudPlay.uz</h1>
            <p className="text-blue-200 text-lg">Moonlight Dashboard</p>
          </header>

          <div className="max-w-2xl mx-auto">
            <div className="bg-white rounded-lg shadow-2xl p-8 mb-6">
              <div className="flex justify-between items-center mb-6">
                <div>
                  <h2 className="text-2xl font-bold text-gray-800">{user.name}</h2>
                  <p className="text-gray-600">{user.email}</p>
                  <p className="text-green-600 font-semibold mt-2">
                    Balans: ${user.balance}
                  </p>
                </div>
                <button
                  onClick={handleLogout}
                  className="px-6 py-2 bg-red-500 text-white rounded-lg hover:bg-red-600 transition-colors"
                >
                  Chiqish
                </button>
              </div>

              {error && (
                <div className="mb-4 p-4 bg-red-100 border border-red-400 text-red-700 rounded-lg">
                  {error}
                </div>
              )}

              {success && (
                <div className="mb-4 p-4 bg-green-100 border border-green-400 text-green-700 rounded-lg">
                  {success}
                </div>
              )}

              {!slot ? (
                <div className="bg-gradient-to-r from-blue-50 to-purple-50 rounded-lg p-6">
                  <h3 className="text-xl font-bold text-gray-800 mb-4">
                    🎮 Moonlight-ni yoqish
                  </h3>
                  <p className="text-gray-600 mb-6">
                    CloudPlay.uz orqali Moonlight gaming slotni bir tugma bosish bilan yoqing!
                  </p>

                  <div className="space-y-4 mb-6">
                    <div>
                      <label className="block text-sm font-medium text-gray-700 mb-2">
                        CloudPlay Username
                      </label>
                      <input
                        type="text"
                        value={formData.cloudplayUsername}
                        onChange={(e) =>
                          setFormData({ ...formData, cloudplayUsername: e.target.value })
                        }
                        className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                        placeholder="CloudPlay username"
                        required
                      />
                    </div>
                    <div>
                      <label className="block text-sm font-medium text-gray-700 mb-2">
                        CloudPlay Parol
                      </label>
                      <input
                        type="password"
                        value={formData.cloudplayPassword}
                        onChange={(e) =>
                          setFormData({ ...formData, cloudplayPassword: e.target.value })
                        }
                        className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                        placeholder="••••••••"
                        required
                      />
                    </div>
                  </div>

                  <button
                    onClick={handleEnableMoonlight}
                    disabled={loading}
                    className="w-full bg-gradient-to-r from-blue-600 to-purple-600 text-white py-4 rounded-lg font-bold text-lg hover:from-blue-700 hover:to-purple-700 transition-all disabled:opacity-50 disabled:cursor-not-allowed transform hover:scale-105"
                  >
                    {loading ? 'Yuklanmoqda...' : '⚡ Moonlight-ni Yoqish'}
                  </button>
                </div>
              ) : (
                <div className="bg-gradient-to-r from-green-50 to-blue-50 rounded-lg p-6">
                  <h3 className="text-2xl font-bold text-green-800 mb-4 flex items-center">
                    ✅ Moonlight Yoqildi!
                  </h3>
                  
                  <div className="space-y-3 bg-white rounded-lg p-5 mb-4">
                    <div className="flex justify-between items-center border-b pb-2">
                      <span className="font-semibold text-gray-700">Slot nomi:</span>
                      <span className="text-gray-900 font-mono">{slot.name}</span>
                    </div>
                    <div className="flex justify-between items-center border-b pb-2">
                      <span className="font-semibold text-gray-700">IP Address:</span>
                      <span className="text-gray-900 font-mono">{slot.ipAddress}</span>
                    </div>
                    <div className="flex justify-between items-center border-b pb-2">
                      <span className="font-semibold text-gray-700">Status:</span>
                      <span className="px-3 py-1 bg-green-100 text-green-800 rounded-full text-sm font-semibold">
                        {slot.status}
                      </span>
                    </div>
                    {slot.pinCode && (
                      <div className="flex justify-between items-center pt-2">
                        <span className="font-semibold text-gray-700">PIN Kod:</span>
                        <span className="text-2xl font-bold text-purple-600 font-mono bg-purple-100 px-4 py-2 rounded-lg">
                          {slot.pinCode}
                        </span>
                      </div>
                    )}
                  </div>

                  <div className="bg-yellow-50 border border-yellow-200 rounded-lg p-4 mb-4">
                    <p className="text-sm text-yellow-800">
                      💡 <strong>Qo'llanma:</strong> Moonlight dasturini oching va "{slot.ipAddress}" 
                      IP manziliga ulanish uchun yuqoridagi PIN kodni ishlating.
                    </p>
                  </div>

                  <button
                    onClick={() => setSlot(null)}
                    className="w-full bg-blue-500 text-white py-3 rounded-lg font-semibold hover:bg-blue-600 transition-colors"
                  >
                    Yangi Slot Yaratish
                  </button>
                </div>
              )}
            </div>

            <div className="grid md:grid-cols-3 gap-4">
              <div className="bg-white/10 backdrop-blur-sm rounded-lg p-4 text-center">
                <div className="text-3xl mb-2">🚀</div>
                <h4 className="text-white font-bold">Avtomatik</h4>
                <p className="text-blue-200 text-sm">Hamma jarayon avtomatik</p>
              </div>
              <div className="bg-white/10 backdrop-blur-sm rounded-lg p-4 text-center">
                <div className="text-3xl mb-2">🔐</div>
                <h4 className="text-white font-bold">Xavfsiz</h4>
                <p className="text-blue-200 text-sm">PIN kod himoyasi</p>
              </div>
              <div className="bg-white/10 backdrop-blur-sm rounded-lg p-4 text-center">
                <div className="text-3xl mb-2">⚡</div>
                <h4 className="text-white font-bold">Tez</h4>
                <p className="text-blue-200 text-sm">Bir klikda yoqish</p>
              </div>
            </div>
          </div>
        </div>
      </div>
    )
  }

  return (
    <div className="min-h-screen bg-gradient-to-br from-blue-900 via-purple-900 to-indigo-900">
      <div className="container mx-auto px-4 py-8">
        <header className="text-center mb-12">
          <h1 className="text-5xl font-bold text-white mb-2">CloudPlay.uz</h1>
          <p className="text-blue-200 text-lg">Moonlight Integration</p>
        </header>

        <div className="max-w-md mx-auto bg-white rounded-lg shadow-2xl overflow-hidden">
          <div className="flex border-b">
            <button
              onClick={() => setIsLogin(true)}
              className={`flex-1 py-4 text-center font-semibold transition-colors ${
                isLogin
                  ? 'bg-blue-600 text-white'
                  : 'bg-gray-100 text-gray-600 hover:bg-gray-200'
              }`}
            >
              Kirish
            </button>
            <button
              onClick={() => setIsLogin(false)}
              className={`flex-1 py-4 text-center font-semibold transition-colors ${
                !isLogin
                  ? 'bg-blue-600 text-white'
                  : 'bg-gray-100 text-gray-600 hover:bg-gray-200'
              }`}
            >
              Ro'yxatdan o'tish
            </button>
          </div>

          <div className="p-8">
            {error && (
              <div className="mb-4 p-4 bg-red-100 border border-red-400 text-red-700 rounded-lg">
                {error}
              </div>
            )}

            {isLogin ? (
              <form onSubmit={handleLogin} className="space-y-4">
                <h2 className="text-2xl font-bold text-gray-800 mb-6">
                  Hisobingizga kiring
                </h2>
                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">
                    Email
                  </label>
                  <input
                    type="email"
                    value={formData.email}
                    onChange={(e) => setFormData({ ...formData, email: e.target.value })}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                    placeholder="email@example.com"
                    required
                  />
                </div>
                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">
                    Parol
                  </label>
                  <input
                    type="password"
                    value={formData.password}
                    onChange={(e) => setFormData({ ...formData, password: e.target.value })}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                    placeholder="••••••••"
                    required
                  />
                </div>
                <button
                  type="submit"
                  disabled={loading}
                  className="w-full bg-blue-600 text-white py-3 rounded-lg font-semibold hover:bg-blue-700 transition-colors mt-6 disabled:opacity-50 disabled:cursor-not-allowed"
                >
                  {loading ? 'Yuklanmoqda...' : 'Kirish'}
                </button>
              </form>
            ) : (
              <form onSubmit={handleRegister} className="space-y-4">
                <h2 className="text-2xl font-bold text-gray-800 mb-6">
                  Yangi hisob yaratish
                </h2>
                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">
                    Ism
                  </label>
                  <input
                    type="text"
                    value={formData.name}
                    onChange={(e) => setFormData({ ...formData, name: e.target.value })}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                    placeholder="Ismingiz"
                    required
                  />
                </div>
                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">
                    Email
                  </label>
                  <input
                    type="email"
                    value={formData.email}
                    onChange={(e) => setFormData({ ...formData, email: e.target.value })}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                    placeholder="email@example.com"
                    required
                  />
                </div>
                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">
                    Parol
                  </label>
                  <input
                    type="password"
                    value={formData.password}
                    onChange={(e) => setFormData({ ...formData, password: e.target.value })}
                    className="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                    placeholder="••••••••"
                    required
                  />
                </div>
                <button
                  type="submit"
                  disabled={loading}
                  className="w-full bg-blue-600 text-white py-3 rounded-lg font-semibold hover:bg-blue-700 transition-colors mt-6 disabled:opacity-50 disabled:cursor-not-allowed"
                >
                  {loading ? 'Yuklanmoqda...' : "Ro'yxatdan o'tish"}
                </button>
              </form>
            )}
          </div>
        </div>

        <div className="mt-12 grid md:grid-cols-3 gap-6 max-w-4xl mx-auto">
          <div className="bg-white/10 backdrop-blur-sm rounded-lg p-6 text-center">
            <div className="text-4xl mb-3">🎮</div>
            <h3 className="text-xl font-bold text-white mb-2">Moonlight</h3>
            <p className="text-blue-200">
              Bir tugma bosish bilan slot yarating
            </p>
          </div>
          <div className="bg-white/10 backdrop-blur-sm rounded-lg p-6 text-center">
            <div className="text-4xl mb-3">🔐</div>
            <h3 className="text-xl font-bold text-white mb-2">PIN Kod</h3>
            <p className="text-blue-200">Avtomatik PIN kod olish</p>
          </div>
          <div className="bg-white/10 backdrop-blur-sm rounded-lg p-6 text-center">
            <div className="text-4xl mb-3">⚡</div>
            <h3 className="text-xl font-bold text-white mb-2">Tez va oson</h3>
            <p className="text-blue-200">Dashboard orqali boshqaring</p>
          </div>
        </div>
      </div>
    </div>
  )
}

export default App
